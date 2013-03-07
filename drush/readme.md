# DSGF Drush Configurations
## It's Drush O'Clock, Do You Know Where Your Developers Are?

This is where everyone who doesn't know what they are doing goes to die.
For real.

### Before using aliases

Drush needs to know to look here for our custom `drushrc.php`, so the first
thing to do is to create or modify your local `~/.drush/drushrc.php` and append 
the following:

```php
// Load a drushrc.php file from the 'drush' folder at the root
// of the current git repository. Customize as desired.
// (Script by grayside; @see: http://grayside.org/node/93)
exec('git rev-parse --git-dir 2> /dev/null', $output);
if (!empty($output)) {
  $repo = $output[0];
  $options['config'] = $repo . '/../drush/drushrc.php';
  $options['include'] = $repo . '/../drush/commands';
  $options['alias-path'] = $repo . '/../drush/aliases';
}
```

The second step is to make sure you have a configuration for `drupalsgf.org` in
your `~/.ssh/config` file. If you don't then, you probably shouldn't be trying
to push to our remote server(s).

### Aliases in use

@dsgf.live
 * The live server

### Using the aliases
```php
# sync the live database to your local installation
drush sql-sync @dsgf.live @self

# sync files from the live site to your local installation
drush rsync @dsgf.live:%files @self:%files
```

