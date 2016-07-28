<?php
/**
 * @file
 * Multi-step Form functions.
 */
/**
 * Implements multi-step form.
 * @param mixed $form
 * @param mixed $form_state
 * @return mixed
 */
function msf_multi_form($form, &$form_state) {
  $form['#prefix'] = '<div id="multi-form-wrapper">';
  $form['#suffix'] = '</div>';

  $form['#tree'] = TRUE;

  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;

  $fields_num = config_pages_get('settings_form', 'field_fields_number_' . $step);

  if (!empty($fields_num) && $fields_num > 0) {
    $form['step' . $step] = array(
      '#type' => 'fieldset',
      '#title' => t("Page %page of Multistep Form", array("%page" => $step)),
    );

    for ($i = 0; $i < $fields_num; $i++) {
      $form['step' . $step]['msf_' . $step . '$i'] = msf_form_fields($form_state, $step, $i);
    }

    $form['actions'] = array('#type' => 'actions');

    if ($step == 2) {
      $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Send'),
      );
      $form['actions']['prev'] = array(
        '#type' => 'submit',
        '#value' => 'Previous',
        '#submit' => array('msf_multi_form_submit'),
        '#ajax' => array(
          'wrapper' => 'multi-form-wrapper',
          'callback' => 'msf_form_ajax_callback',
        ),
      );
    }

    if ($step < 2) {
      $form['actions']['next'] = array(
        '#type' => 'submit',
        '#value' => t('Next'),
        '#submit' => array('msf_multi_form_submit'),
        '#ajax' => array(
          'wrapper' => 'multi-form-wrapper',
          'callback' => 'msf_form_ajax_callback',
        ),
      );
    }
  } else {
    $form['message'] = array(
      '#markup' => t('Please, set number of fields for the form here: ') .
        l('form settings', 'admin/test_form_settings'),
    );
  }

  return $form;
}

/**
 * Implements ajax callback for the form.
 * @param mixed $form
 * @param mixed $form_state
 * @return mixed
 */
function msf_form_ajax_callback($form, $form_state) {
  return $form;
}

/**
 * Implements submit callback for the form.
 * @param mixed $form
 * @param mixed $form_state
 */
function msf_multi_form_submit($form, &$form_state) {
  $current_step = 'step' . $form_state['storage']['step'];
  if (!empty($form_state['values'][$current_step])) {
    $form_state['storage']['values'][$current_step] = $form_state['values'][$current_step];
  }

  if (isset($form['actions']['next']['#value']) && $form_state['triggering_element']['#value'] == $form['actions']['next']['#value']) {
    $form_state['storage']['step']++;

    $step_name = 'step' . $form_state['storage']['step'];
    if (!empty($form_state['storage']['values'][$step_name])) {
      $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
    }
  }

  if (isset($form['actions']['prev']['#value']) && $form_state['triggering_element']['#value'] == $form['actions']['prev']['#value']) {
    $form_state['storage']['step']--;

    $step_name = 'step' . $form_state['storage']['step'];
    $form_state['values'][$step_name] = $form_state['storage']['values'][$step_name];
  }

  if (isset($form['actions']['submit']['#value']) && $form_state['triggering_element']['#value'] == $form['actions']['submit']['#value']) {

    msf_send_mail($form_state['storage']['values']);

    $form_state['rebuild'] = FALSE;
    return;
  }

  $form_state['rebuild'] = TRUE;
}
