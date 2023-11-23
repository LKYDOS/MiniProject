<?php
/**
 * @package CoffeeTech
 */
/*
Plugin Name: CoffeeTech
Description: Manage the detail of a workshop (i.e. workshop title; physical vs. online workshop; a workshop that last for several days; a workshop series; any quota for the number of people to join the workshop; speakers)
Version: 1.0.0
Author: Lui Ka Yung
Author URI: https://coffeemachine8.wordpress.com/
*/

if (!defined ('ABSPATH')){
    exit;
}

add_action( 'admin_menu', 'mfp_add_menu' );
function mfp_add_menu() {
add_menu_page(
'Coffee Workshops', // Title of the page
'Workshops\' Management', // Text to show on the menu link
'manage_options', // Capability requirement to see the link
'CoffeeTech/WorkshopDetails.php' // The file to load when the user clicked on it
); }
