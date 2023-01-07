% LV95-CONVERTER(1) lv95-converter 1.0.4
% Timo Früh
% January 2023

# NAME
lv95-converter - Convert LV95 coordinates to WGS84 and vice-versa

# SYNOPSIS
**lv95-converter** [*OPTIONS*] \
**lv95-converter** *SUBCOMMAND* [*SUBCOMMAND-OPTIONS*]

# DESCRIPTION
**lv95-converter** calculates Swiss LV95 coordinates from WGS84 coordinates or the other way around.
The specified subcommand decides, in which direction the calculation is to be done. \
Be wary while converting WGS84 to LV95, however, as the results will be meaningless if the WGS84 coordinates are not located within Switzerland.

# OPTIONS
**-h**, **\--help**
: Displays a help message

**-v**, **\--version**
: Displays the software version

## Subcommands
**lv95**
: Convert from LV95 to WGS84

**wgs84**
: Convert from WGS84 to LV95

## Subcommand Options
**-h**, **\--help**
: Displays a help message (about the subcommand)

**-e**, **\--east**=easting-coordinate
: The easting coordinate in the format corresponding to the subcommand

**-n**, **\--north**=northing-coordinate
: The northing coordinate in the format corresponding to the subcommand

# EXAMPLES
**lv95-converter -h**
: Displays the help message

**lv95-converter lv95 -h**
: Displays the help message for the lv95 subcommand

**lv95-converter lv95 -e 2600000 -n 1200000**
: Converts the LV95 coordinates 2600000 1200000 to WGS84

# BUGS
I should think so. \
Please refer to <https://github.com/tifrueh/lv95-converter/issues>

# COPYRIGHT
Copyright (C) 2022-2023 Timo Früh

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
