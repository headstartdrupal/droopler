<?php

/**
 * @file
 * File declaring drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function d_update_drush_command() {
  $commands['generate-config-hash'] = [
    'description' => 'Generates hash for entered config',
    'aliases' => ['gch'],
    'options' => [
      'config' => 'Config name',
    ],
    'examples' => [
      'drush gch node.type.content_page' => 'Generates hash for node type article',
    ],
  ];

  return $commands;
}

/**
 * Drush command logic for generating config hash.
 */
function drush_d_update_generate_config_hash($opt = NULL) {
  $service_name = 'd_update.drush.generate_config_hash_command';

  if (!\Drupal::hasService($service_name)) {
    drush_print(dt('Service to generate hash is missing.'));
    return;
  }

  if (empty(($opt))) {
    drush_print(dt('Config name can not be empty, please insert valid config name.'));
    return;
  }

  \Drupal::service($service_name)->generate($opt);
}
