<?php
/**
 * @file
 * config_page_settings_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function config_page_settings_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'config_pages-settings_form-field_fields_number_1'.
  $field_instances['config_pages-settings_form-field_fields_number_1'] = array(
    'bundle' => 'settings_form',
    'default_value' => array(
      0 => array(
        'value' => 2,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'config_pages',
    'field_name' => 'field_fields_number_1',
    'label' => 'Fields number for the first step',
    'required' => 0,
    'settings' => array(
      'max' => 5,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'config_pages-settings_form-field_fields_number_2'.
  $field_instances['config_pages-settings_form-field_fields_number_2'] = array(
    'bundle' => 'settings_form',
    'default_value' => array(
      0 => array(
        'value' => 2,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'config_pages',
    'field_name' => 'field_fields_number_2',
    'label' => 'Fields number for the second step',
    'required' => 0,
    'settings' => array(
      'max' => 5,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'config_pages-settings_form-field_mail_to'.
  $field_instances['config_pages-settings_form-field_mail_to'] = array(
    'bundle' => 'settings_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'config_pages',
    'field_name' => 'field_mail_to',
    'label' => 'Mail to',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fields number for the first step');
  t('Fields number for the second step');
  t('Mail to');

  return $field_instances;
}
