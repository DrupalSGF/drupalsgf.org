<?php

/**
 * DrupalSGF.org drushrc.php file.
 *
 * @see example.drushrc.php
 */


/*
 * Customize this associative array with your own tables. This is the list of
 * tables whose *data* is skipped by the 'sql-dump' and 'sql-sync' commands when
 * a structure-tables-key is provided. You may add new tables to the existing
 * array or add a new element.
 */
$options['structure-tables'] = array(
 'common' => array('cache', 'cache_filter', 'cache_menu', 'cache_page', 'history', 'sessions', 'watchdog'),
);

// Download a copy of the database from the live environment to our
// local installation.
$options['shell-aliases']['pulldb'] = '!drush sql-sync @dsgf.live @self --yes --create-db && drush sql-sanitize -y';
// Download images from the live environment to our local installation.
$options['shell-aliases']['rsync-images'] = '!drush rsync @dsgf.live:%files/ @self:%files --include=*.png --include=*.jpg --exclude=* -vaz';

