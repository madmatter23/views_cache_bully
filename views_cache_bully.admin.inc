<?php

/**
 * @file
 * Administrative form callbacks for views_cache_bully.
 */

/**
 * Form callback for views cache bully admin settings form.
 */
function views_cache_bully_admin_form() {
  $options = array(60, 300, 1800, 3600, 21600, 518400);
  $options = drupal_map_assoc($options, 'format_interval');
  $options = array(-1 => t('Never cache')) + $options;

  $form['views_cache_bully_results_lifespan'] = array(
    '#type' => 'select',
    '#title' => t('Query results'),
    '#description' => t('The length of time raw query results should be cached.'),
    '#options' => $options,
    '#default_value' => variable_get('views_cache_bully_results_lifespan', 3600),
  );
  $form['views_cache_bully_output_lifespan'] = array(
    '#type' => 'select',
    '#title' => t('Rendered output'),
    '#description' => t('The length of time rendered HTML output should be cached.'),
    '#options' => $options,
    '#default_value' => variable_get('views_cache_bully_output_lifespan', 3600),
  );
  $form['views_cache_bully_exempt_exposed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exempt all views with exposed forms from bullying'),
    '#description' => t('Views using exposed forms will not be cached by Views Cache Bully.'),
    '#default_value' => variable_get('views_cache_bully_exempt_exposed', TRUE),
  );
  $views = drupal_map_assoc(array_keys(views_get_all_views()));
  $form['views_cache_bully_exemptions'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Exempt the following views from bullying'),
    '#description' => t('Checked views will not be cached.'),
    '#options' => $views,
    '#default_value' => variable_get('views_cache_bully_exemptions', array()),
  );

  return system_settings_form($form);
}
