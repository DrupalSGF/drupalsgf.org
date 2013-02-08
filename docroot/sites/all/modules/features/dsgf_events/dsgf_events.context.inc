<?php
/**
 * @file
 * dsgf_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dsgf_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dsgf_event';
  $context->description = '';
  $context->tag = 'event';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-events-block' => array(
          'module' => 'views',
          'delta' => 'events-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('event');
  $export['dsgf_event'] = $context;

  return $export;
}
