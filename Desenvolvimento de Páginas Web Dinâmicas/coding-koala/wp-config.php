<?php
/**
 * A configuração de base do WordPress
 *
 * Este ficheiro define os seguintes parâmetros: MySQL settings, Table Prefix,
 * Secret Keys, WordPress Language, e ABSPATH. Pode obter mais informação
 * visitando {@link http://codex.wordpress.org/Editing_wp-config.php Editing
 * wp-config.php} no Codex. As definições de MySQL são-lhe fornecidas pelo seu serviço de alojamento.
 *
 * Este ficheiro contém as seguintes configurações:
 *
 * * Configurações de  MySQL
 * * Chaves secretas
 * * Prefixo das tabelas da base de dados
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** Definições de MySQL - obtenha estes dados do seu serviço de alojamento** //
/** O nome da base de dados do WordPress */
define( 'DB_NAME', 'wordpress_carlostojal' );

/** O nome do utilizador de MySQL */
define( 'DB_USER', 'root' );

/** A password do utilizador de MySQL  */
define( 'DB_PASSWORD', '' );

/** O nome do serviddor de  MySQL  */
define( 'DB_HOST', 'localhost' );

/** O "Database Charset" a usar na criação das tabelas. */
define( 'DB_CHARSET', 'utf8mb4' );

/** O "Database Collate type". Se tem dúvidas não mude. */
define('DB_COLLATE', '');

/**#@+
 * Chaves únicas de autenticação.
 *
 * Mude para frases únicas e diferentes!
 * Pode gerar frases automáticamente em {@link https://api.wordpress.org/secret-key/1.1/salt/ Serviço de chaves secretas de WordPress.org}
 * Pode mudar estes valores em qualquer altura para invalidar todos os cookies existentes o que terá como resultado obrigar todos os utilizadores a voltarem a fazer login
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'XI!,<A;+|RfQCT?e?1Sce+|@(]w?S)^51B6=uoopT0G.l]*(o7NiKUvp6w:U}`8S' );
define( 'SECURE_AUTH_KEY',  'z7)|e7`I[Hh$41H)SH^0 O/]sXsYho>pwI/q)F^Z:K9}YXLG1et}mn1A[%c{]GOM' );
define( 'LOGGED_IN_KEY',    'gu/Pxff(YpgMvIjn;]SfaDr:g=8sE9~_qU3;G[Jr-^IC.14(9P]#07*I+xnxC@FJ' );
define( 'NONCE_KEY',        'wBz;F6?ebV$R3[Lv>}fLP6T5C0PidSsjOwA@UHXjv/DmlqO D=~nYr@%s%=hW<MZ' );
define( 'AUTH_SALT',        '1~85GDD|W|/;{Dt?ES-,z$o~?9sT !Hy?w^a^I`g19}L2NE3]:q>J(yQ_n{~hWT+' );
define( 'SECURE_AUTH_SALT', 'q$ v!EM5YWg+pX>*XM_GBCq-Q@4&D?^/S9!eu3.T=I/4<d2$OSOlS/5T]Nq !(A|' );
define( 'LOGGED_IN_SALT',   '+Tb891&JsLq|cG(/DKq5mX2y+xZN&!?~`]Vqd4JahNP%qIx:f><NXmV7{P^wX9v`' );
define( 'NONCE_SALT',       'Lr9UZn!}sbwoZ7xmrSilQIw*/4z/w+;nD/DH%|RX#3[C*UN/9DYBkHKD_S,rk9].' );

/**#@-*/

/**
 * Prefixo das tabelas de WordPress.
 *
 * Pode suportar múltiplas instalações numa só base de dados, ao dar a cada
 * instalação um prefixo único. Só algarismos, letras e underscores, por favor!
 */
$table_prefix = 'wp_';

/**
 * Para developers: WordPress em modo debugging.
 *
 * Mude isto para true para mostrar avisos enquanto estiver a testar.
 * É vivamente recomendado aos autores de temas e plugins usarem WP_DEBUG
 * no seu ambiente de desenvolvimento.
 *
 * Para mais informações sobre outras constantes que pode usar para debugging,
 * visite o Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_DEBUG', false);

/* E é tudo. Pare de editar! */

/** Caminho absoluto para a pasta do WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Define as variáveis do WordPress e ficheiros a incluir. */
require_once(ABSPATH . 'wp-settings.php');
