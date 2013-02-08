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
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'events' => 'events',
        'events:page' => 'events:page',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('event');
  $export['dsgf_event'] = $context;

  return $export;
}
