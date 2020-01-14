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
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_carlostojal' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

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
define( 'AUTH_KEY',         '#Vz;J+FbgAz*naEH0~VWGThYi9`:H-{E.>PN&dfk8-@O$R~/RyqFe70B,?`v-eO*' );
define( 'SECURE_AUTH_KEY',  '*[R }$vLmK[#_ly^W#i?a=p.U^y)Kr-O?;2V2<_umF1UhLraOC3YQIJ7=^a,KBk,' );
define( 'LOGGED_IN_KEY',    '.-@*5;P]P@GH^Is|c>YbHupbOq:e}F&npp&wd1tc48c=@ch=s$$e3?am&ORc5MZc' );
define( 'NONCE_KEY',        '(q=-U<B@/|jC[90bkH,k7Xn$X)I=8N#bMW_tsNEn<`v~%`54H]SjF7H0_Trn?r8~' );
define( 'AUTH_SALT',        'yGx.h`2l[loG_v%c*J&.)Mmw <06*@%M}NY0y`jS ((&lZ;?k35){xC3g!klQz^`' );
define( 'SECURE_AUTH_SALT', 't)!,KM%&q^X594N}zI{8!<x`A)glLOBhX82TjHnNxsZimSPu$BKIqY8PG[C~)6#4' );
define( 'LOGGED_IN_SALT',   'Q8uf33xGswmY0_!Xk:9]B+QD:[He_l*|.3{DlL;7G_UY/.;6.?%:.>)<QW%b%%AV' );
define( 'NONCE_SALT',       'r,H/EF,bI~)!Uf7?Z(lj:#n T]%Hu2k66:dd@3Ty/Bp-#p97xx0Z0G%<V~5$E1e[' );

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
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );

