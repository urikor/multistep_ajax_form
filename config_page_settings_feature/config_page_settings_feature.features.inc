<?php
/**
 * @file
 * config_page_settings_feature.features.inc
 */

/**
 * Implements hook_default_config_pages_type().
 */
function config_page_settings_feature_default_config_pages_type() {
  $items = array();
  $items['settings_form'] = entity_import('config_pages_type', '{
    "type" : "settings_form",
    "label" : "Test Form Settings",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/test_form_settings", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
