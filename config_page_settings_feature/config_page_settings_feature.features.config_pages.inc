<?php
/**
 * @file
 * config_page_settings_feature.features.config_pages.inc
 */

/**
 * Implements hook_config_pages_default_data().
 */
function config_page_settings_feature_config_pages_default_data() {
  $config_pages = array();

  // Exported format: settings_form-.
  $config_pages['settings_form-'] = array(
    'context' => '',
    'data' => '',
    'field_fields_number_1' => array(
      'und' => array(
        0 => array(
          'value' => 1,
        ),
      ),
    ),
    'field_fields_number_2' => array(
      'und' => array(
        0 => array(
          'value' => 2,
        ),
      ),
    ),
    'field_mail_subject' => array(),
    'field_mail_to' => array(
      'und' => array(
        0 => array(
          'value' => 'urikor@mail.ru',
          'format' => NULL,
          'safe_value' => 'urikor@mail.ru',
        ),
      ),
    ),
    'type' => 'settings_form',
  );

  return $config_pages;
}
