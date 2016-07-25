<?php
/**
 * Implements form fields array.
 * @param mixed $form_state
 * @param integer $step
 * @param integer $i
 * @return array
 */
function  msf_form_fields($form_state, $step, $i) {
    $field = array(
      '#type' => 'textfield',
      '#title' => t("Field %page", array("%page" => $step)) . $i,
      '#size' => 60,
      '#maxlength' => 128,
    );

    if (isset($form_state['values']["step$step"]["msf_$step" . "$i"])) {
      $field['#default_value'] = $form_state['values']["step$step"]["msf_$step" . "$i"];
    }

  return $field;
}

/**
 * Implements mail sending.
 * @param mixed $form_data
 * @throws Exception
 */
function msf_send_mail($form_data) {
  $module = 'multi_form';
  $key = 'multi_form_values';
  $to = config_pages_get('settings_form', "field_mail_to");
  $language = language_default();
  $params = array();
  $from = variable_get('site_mail', 'mail@example.com');
  $send = FALSE;

  if (empty($to)) {
    drupal_set_message(t('Please, set email address here: ') .
      l('form settings', 'admin/test_form_settings'), 'error');

    return;
  }
  try {
    $message = drupal_mail($module, $key, $to, $language, $params, $from, $send);

    $message['subject'] = 'subj';
    $message['body'] = array();

    foreach ($form_data as $step => $values) {
      $message['body'][] = "$step:";
      foreach ($values as $key => $value) {
        $message['body'][] = "Field $key - $value";
      }
    }

    $system = drupal_mail_system($module, $key);
    $message = $system->format($message);
    $message['result'] = $system->mail($message);

    drupal_set_message(t('Your message has been sent.'));

  } catch (Exception $e) {
    $msg = $e->getMessage();
    watchdog('widget', $e->getMessage(), WATCHDOG_ERROR);
    drupal_set_message(t('Error sending message: ') . $msg, 'error');
  }
}
