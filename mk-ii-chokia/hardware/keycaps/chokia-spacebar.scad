// the point of this file is to be a sort of DSL for constructing keycaps.
// when you create a method chain you are just changing the parameters
// key.scad uses, it doesn't generate anything itself until the end. This
// lets it remain easy to use key.scad like before (except without key profiles)
// without having to rely on this file. Unfortunately that means setting tons of
// special variables, but that's a limitation of SCAD we have to work around

use <src/key.scad>

include <src/settings.scad>
include <src/key_sizes.scad>
include <src/key_profiles.scad>
include <src/key_types.scad>
include <src/key_transformations.scad>

//https://github.com/rsheldiii/KeyV2/blob/master/src/settings.scad

//$has_brim=true;
$inverted_dish = true;
$key_length = 3;
$stem_inset = 2;

$key_shape_type = "rounded_square"; // iso_enter sculpted_square rounded_square square oblong

//$stabilizer_type = "cherry_stabilizer"; // [costar_stabilizer, cherry_stabilizer, disable]

// be reet, use the outside two?
// $stabilizers = $key_length >= 6 ? [[-50, 0], [50, 0]] : $key_length >= 2 ? [[-12,0],[12,0]] : [];

//$rounded_key = true; // good but intense

 dcs_row(1) {
     $dish_type =  "sideways cylindrical";
     key();
 }
