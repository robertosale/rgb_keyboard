/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "rgb_keyboard.h"

#include <fstream>
#include <utility>

//loads custom pattern configuration from a file
int rgb_keyboard::keyboard::load_custom( std::string File ){
	
	//open file
	std::ifstream config_in( File );
	if( !config_in.is_open() ){
		return 1;
	}
	
	//process file
	std::string value1 = "";
	std::string value2 = "";
	uint8_t val_r = 0, val_g = 0, val_b = 0;
	std::array<uint8_t, 3> val_rgb;
	std::size_t position = 0;
	
	for( std::string line; std::getline(config_in, line); ){
		//process individual line
		if( line.length() != 0 ){
			if( line[0] != '#' ){
				position = 0;
				position = line.find("\t", position);
				value1 = line.substr(0, position);
				value2 = line.substr(position+1);
													
				//store values in map
				if( value2.length() == 6 ){
					val_r = stoi( value2.substr(0,2), 0, 16 );
					val_g = stoi( value2.substr(2,2), 0, 16 );
					val_b = stoi( value2.substr(4,2), 0, 16 );
					val_rgb = { val_r, val_g, val_b };
					_key_colors[value1] = val_rgb;
				}
			}
		}
	}
	
	return 0;
}

//loads keymap from file
int rgb_keyboard::keyboard::load_keymap( std::string File ){
	
	//open file
	std::ifstream config_in( File );
	if( !config_in.is_open() ){
		return 1;
	}
	
	
	// read file
	std::string line, current_section = "";
	std::vector< std::vector< std::string > > macro_commands;
	macro_commands.resize( 100 );
	while( std::getline(config_in, line) ){
		
		// is empty?
		if( line.length() == 0 )
			continue;
		
		// is comment?
		if( line[0] == ';' || line[0] == '#' )
			continue;
		
		// remove whitespace
		line = std::regex_replace( line, std::regex("[[:space:]]"), "" );
		
		// section header?
		if( std::regex_match( line, std::regex("\\[[[:print:]]+\\]") ) ){
			current_section = std::regex_replace( line, std::regex("[\\[\\]]"), "" );
			continue;
		}
		
		// is section == keymap
		if( current_section == "keymap" ){
			
			// key=value ?
			if( std::regex_match( line, std::regex("[[:print:]]+=[[:print:]]+") ) ){
				_keymap.emplace( std::regex_replace( line, std::regex("=[[:print:]]+"), "" ),
					std::regex_replace( line, std::regex("[[:print:]]+="), "" ) );
			}
			
		// is section a macro definition ?
		} else if( std::regex_match( current_section, std::regex("macro[0-9]+") ) ){
			
			// get number of macro
			std::string macroname = current_section;
			int macronumber = std::stoi( macroname.erase(0, 5) );
			
			// check for range of macronumber, store macro command
			if( macronumber <= 100 && macronumber >= 1 ){
				macro_commands[macronumber-1].push_back(line);
			}
			
		}
		
	}
	
	/*
	for( int i = 0; i < macro_commands.size(); i++ ){
		std::cout << i+1 << " macro\n";
		for( auto j : macro_commands[i] ){
			std::cout << j << "\n";
		}
	}*/
	
	// prepare usb packets for macros (test data)
	uint8_t _data_macros_0[] = {
		0x04, 0x5d, 0x06, 0x0a, 0x2a, 0x00, 0x00, 0x00,
		0xaa, 0x55, 0x32, 0x00, 0x01, 0x00, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x12, 0x00, 0x02, 0x00, 0x01, 0x06, 0x05, 0xa0,
		0x02, 0x08, 0x00, 0x20, 0x02, 0x08, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	std::copy(std::begin(_data_macros_0), std::end(_data_macros_0), std::begin(_data_macros[0]));
	_num_macro_packets = 1;
	
	return 0;
}
