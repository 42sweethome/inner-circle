<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         '+u@oDB@U!R6_gZ:94$$S^U/&v-aX_C@8OPjR/+myf8Qk}nCMQ|XM67gMQ#czj=/]');
define('SECURE_AUTH_KEY',  'PRg]u_XDQ|B+$jKO-7,8FB+PIiaLdFEL_[;rtpf|K7G3D}/SxY O@H4Wit|.|pq@');
define('LOGGED_IN_KEY',    '?G@Mtv5~<#&$%KL?q*q?VfNTe^hCciAMIlFhA-20r*7ern+I=&[}klw<||2Aes?p');
define('NONCE_KEY',        '9ppz43) ic*4^5Ry[)%ftsdk<Z&JNN8+4UQfSxk(:mt3SJN^]RNU4.a(W1Xg0$/,');
define('AUTH_SALT',        'b|F-?klungi1AH+3jsULteJ~ER;i(6G_;1SUOLhOO+@YlBQ+UR;x=|d,mz1Vj/~~');
define('SECURE_AUTH_SALT', 'm~vwb2hxCc|B7u2.CPj9U#G-9cv!woADxKtq`AY9In7!<;@N& 2];rT>b1#o=s-V');
define('LOGGED_IN_SALT',   '=~H _r]3R%+-mki(AuDZ3:]0+h,k+D-tiLP;NR,diE7A,!V?DU`FVKh0|Tib8E,W');
define('NONCE_SALT',       '+OOC6Dw1.:>*-nfJNudIp{ym>-q]?IlW}?T;MtHPKoPS7-*u,+r{2~_xm3?3tZ%0');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
