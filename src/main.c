  
#include <pebble.h>
#include "main.h"
#include "new_round_confirmation.h"
  
static Window *window;

static GBitmap *action_icon_plus;
static GBitmap *action_icon_minus;
static GBitmap *action_icon_retry;

static StatusBarLayer *s_status_bar;

static ActionBarLayer *action_bar;

static TextLayer *header_text_layer;
static TextLayer *body_text_layer;
static TextLayer *label_text_layer;
static TextLayer *total_text_layer;
static TextLayer *putts_text_layer;
static TextLayer *teeaccuracy_text_layer;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
static void update_text() {
  
  static char body_text[50];
  snprintf(body_text, sizeof(body_text), "%u", num_current_hole);
  text_layer_set_text(body_text_layer, body_text);

  static char putt_text[50];
  snprintf(putt_text, sizeof(putt_text), "%u", num_current_hole_putts);
  text_layer_set_text(putts_text_layer, putt_text);  

  
  static char total_text[50];
  
  #if defined(PBL_RECT)

  snprintf(total_text, sizeof(total_text), "Total: %u", num_total);
  printf("This is a rectangular display!");
  
  #elif defined(PBL_ROUND)
 
  snprintf(total_text, sizeof(total_text), "%u", num_total);
  
  #endif
  
  text_layer_set_text(total_text_layer, total_text);
  
  static char hole_text[50];
  snprintf(hole_text, sizeof(hole_text), "Hole %u", num_hole);
  text_layer_set_text(header_text_layer, hole_text);
  
}

// Add a stroke to your score
static void add_to_score(ClickRecognizerRef recognizer,void *context){
  
  num_total++;
 
  switch(num_hole){
    case 1:
      num_hole1++;
      num_current_hole = num_hole1;
    break;
    case 2:
      num_hole2++;
      num_current_hole = num_hole2;
    break;
    case 3:
      num_hole3++;
      num_current_hole = num_hole3;
    break;
    case 4:
      num_hole4++;
      num_current_hole = num_hole4;
    break;
    case 5:
      num_hole5++;
      num_current_hole = num_hole5;
    break;
    case 6:
      num_hole6++;
      num_current_hole = num_hole6;
    break;
    case 7:
      num_hole7++;
      num_current_hole = num_hole7;
    break;
    case 8:
      num_hole8++;
      num_current_hole = num_hole8;
    break;
    case 9:
      num_hole9++;
      num_current_hole = num_hole9;
    break;
    case 10:
      num_hole10++;
      num_current_hole = num_hole10;
    break;
    case 11:
      num_hole11++;
      num_current_hole = num_hole11;
    break;
    case 12:
      num_hole12++;
      num_current_hole = num_hole12;
    break;
    case 13:
      num_hole13++;
      num_current_hole = num_hole13;
    break;
    case 14:
      num_hole14++;
      num_current_hole = num_hole14;
    break;
    case 15:
    num_hole15++;
      num_current_hole = num_hole15;
    break;
    case 16:
      num_hole16++;
      num_current_hole = num_hole16;
    break;
    case 17:
      num_hole17++;
      num_current_hole = num_hole17;
    break;
    case 18:
      num_hole18++;
      num_current_hole = num_hole18;
    break;
  }
  
  update_text();
  
}

// Subtract from the score
static void subtract_from_score(ClickRecognizerRef recognizer,void *context){
  
   if (num_current_hole <= 0) {
    // Keep the counter at zero
    return;
  }
  
  if (num_total <= 0) {
    // Keep the counter at zero
    return;
  }
  
  num_total--;
  
  switch(num_hole){
    case 1:
      num_hole1--;
      num_current_hole = num_hole1;
    break;
    case 2:
      num_hole2--;
      num_current_hole = num_hole2;
    break;
    case 3:
      num_hole3--;
      num_current_hole = num_hole3;
    break;
    case 4:
      num_hole4--;
      num_current_hole = num_hole4;
    break;
    case 5:
      num_hole5--;
      num_current_hole = num_hole5;
    break;
    case 6:
      num_hole6--;
      num_current_hole = num_hole6;
    break;
    case 7:
      num_hole7--;
      num_current_hole = num_hole7;
    break;
    case 8:
      num_hole8--;
      num_current_hole = num_hole8;
    break;
    case 9:
      num_hole9--;
      num_current_hole = num_hole9;
    break;
    case 10:
      num_hole10--;
      num_current_hole = num_hole10;
    break;
    case 11:
      num_hole11--;
      num_current_hole = num_hole11;
    break;
    case 12:
      num_hole12--;
      num_current_hole = num_hole12;
    break;
    case 13:
      num_hole13--;
      num_current_hole = num_hole13;
    break;
    case 14:
      num_hole14--;
      num_current_hole = num_hole14;
    break;
    case 15:
    num_hole15--;
      num_current_hole = num_hole15;
    break;
    case 16:
      num_hole16--;
      num_current_hole = num_hole16;
    break;
    case 17:
      num_hole17--;
      num_current_hole = num_hole17;
    break;
    case 18:
      num_hole18--;
      num_current_hole = num_hole18;
    break;
  }
  
  update_text();
  
}

// Add a putt to the hole
static void add_putt_to_hole (ClickRecognizerRef recognizer, void *context) {
  
    switch(num_hole){
    case 1:
      num_hole1_putts++;
      num_current_hole_putts = num_hole1_putts;
    break;
    case 2:
      num_hole2_putts++;
      num_current_hole_putts = num_hole2_putts;
    break;
    case 3:
      num_hole3_putts++;
      num_current_hole_putts = num_hole3_putts;
    break;
    case 4:
      num_hole4_putts++;
      num_current_hole_putts = num_hole4_putts;
    break;
    case 5:
      num_hole5_putts++;
      num_current_hole_putts = num_hole5_putts;
    break;
    case 6:
      num_hole6_putts++;
      num_current_hole_putts = num_hole6_putts;
    break;
    case 7:
      num_hole7_putts++;
      num_current_hole_putts = num_hole7_putts;
    break;
    case 8:
      num_hole8_putts++;
      num_current_hole_putts = num_hole8_putts;
    break;
    case 9:
      num_hole9_putts++;
      num_current_hole_putts = num_hole9_putts;
    break;
    case 10:
      num_hole10_putts++;
      num_current_hole_putts = num_hole10_putts;
    break;
    case 11:
      num_hole11_putts++;
      num_current_hole_putts = num_hole11_putts;
    break;
    case 12:
      num_hole12_putts++;
      num_current_hole_putts = num_hole12_putts;
    break;
    case 13:
      num_hole13_putts++;
      num_current_hole_putts = num_hole13_putts;
    break;
    case 14:
      num_hole14_putts++;
      num_current_hole_putts = num_hole14_putts;
    break;
    case 15:
    num_hole15_putts++;
      num_current_hole_putts = num_hole15_putts;
    break;
    case 16:
      num_hole16_putts++;
      num_current_hole_putts = num_hole16_putts;
    break;
    case 17:
      num_hole17_putts++;
      num_current_hole_putts = num_hole17_putts;
    break;
    case 18:
      num_hole18_putts++;
      num_current_hole_putts = num_hole18_putts;
    break;
  }
  
  update_text();
}

// Subtract a putt from the hole
static void subtract_putt_from_hole (ClickRecognizerRef recognizer, void *context) {
  
    switch(num_hole){
    case 1:
      num_hole1_putts--;
      num_current_hole_putts = num_hole1_putts;
    break;
    case 2:
      num_hole2_putts--;
      num_current_hole_putts = num_hole2_putts;
    break;
    case 3:
      num_hole3_putts--;
      num_current_hole_putts = num_hole3_putts;
    break;
    case 4:
      num_hole4_putts--;
      num_current_hole_putts = num_hole4_putts;
    break;
    case 5:
      num_hole5_putts--;
      num_current_hole_putts = num_hole5_putts;
    break;
    case 6:
      num_hole6_putts--;
      num_current_hole_putts = num_hole6_putts;
    break;
    case 7:
      num_hole7_putts--;
      num_current_hole_putts = num_hole7_putts;
    break;
    case 8:
      num_hole8_putts--;
      num_current_hole_putts = num_hole8_putts;
    break;
    case 9:
      num_hole9_putts--;
      num_current_hole_putts = num_hole9_putts;
    break;
    case 10:
      num_hole10_putts--;
      num_current_hole_putts = num_hole10_putts;
    break;
    case 11:
      num_hole11_putts--;
      num_current_hole_putts = num_hole11_putts;
    break;
    case 12:
      num_hole12_putts--;
      num_current_hole_putts = num_hole12_putts;
    break;
    case 13:
      num_hole13_putts--;
      num_current_hole_putts = num_hole13_putts;
    break;
    case 14:
      num_hole14_putts--;
      num_current_hole_putts = num_hole14_putts;
    break;
    case 15:
    num_hole15_putts--;
      num_current_hole_putts = num_hole15_putts;
    break;
    case 16:
      num_hole16_putts--;
      num_current_hole_putts = num_hole16_putts;
    break;
    case 17:
      num_hole17_putts--;
      num_current_hole_putts = num_hole17_putts;
    break;
    case 18:
      num_hole18_putts--;
      num_current_hole_putts = num_hole18_putts;
    break;
  }
  
  update_text();
}

// Skip back to the previous holes
static void hole_backwards(ClickRecognizerRef recognizer,void *context){
  num_hole--;
  
  if (num_hole < 1) {
    // Keep the counter at zero
    return;
  }
  
  switch(num_hole){
    case 1:
      num_current_hole = num_hole1;
      num_current_hole_putts = num_hole1_putts;
    break;
    case 2:
      num_current_hole = num_hole2;
      num_current_hole_putts = num_hole2_putts;
    break;
    case 3:
      num_current_hole = num_hole3;
      num_current_hole_putts = num_hole3_putts;
    break;
    case 4:
      num_current_hole = num_hole4;
      num_current_hole_putts = num_hole4_putts;
    break;
    case 5:
      num_current_hole = num_hole5;
      num_current_hole_putts = num_hole5_putts;
    break;
    case 6:
      num_current_hole = num_hole6;
      num_current_hole_putts = num_hole6_putts;
    break;
    case 7:
      num_current_hole = num_hole7;
      num_current_hole_putts = num_hole7_putts;
    break;
    case 8:
      num_current_hole = num_hole8;
      num_current_hole_putts = num_hole8_putts;
    break;
    case 9:
      num_current_hole = num_hole9;
      num_current_hole_putts = num_hole9_putts;
    break;
    case 10:
      num_current_hole = num_hole10;
      num_current_hole_putts = num_hole10_putts;
    break;
    case 11:
      num_current_hole = num_hole11;
      num_current_hole_putts = num_hole11_putts;
    break;
    case 12:
      num_current_hole = num_hole12;
      num_current_hole_putts = num_hole12_putts;
    break;
    case 13:
      num_current_hole = num_hole13;
      num_current_hole_putts = num_hole12_putts;
    break;
    case 14:
      num_current_hole = num_hole14;
      num_current_hole_putts = num_hole14_putts;
    break;
    case 15:
      num_current_hole = num_hole15;
      num_current_hole_putts = num_hole15_putts;
    break;
    case 16:
      num_current_hole = num_hole16;
      num_current_hole_putts = num_hole16_putts;
    break;
    case 17:
      num_current_hole = num_hole17;
      num_current_hole_putts = num_hole17_putts;
    break;
    case 18:
      num_current_hole = num_hole18;
      num_current_hole_putts = num_hole18_putts;
    break;
  }
 
  update_text();
  
}

// skip forward to upcoming holes
static void hole_forward(ClickRecognizerRef recognizer,void *context){
  
  num_hole++;
  
  if (num_hole > 18) {
    // Keep the counter at zero
    num_hole = 18;
  }
  
  switch(num_hole){
    case 1:
      num_current_hole = num_hole1;
      num_current_hole_putts = num_hole1_putts;
    break;
    case 2:
      num_current_hole = num_hole2;
      num_current_hole_putts = num_hole2_putts;
    break;
    case 3:
      num_current_hole = num_hole3;
      num_current_hole_putts = num_hole3_putts;
    break;
    case 4:
      num_current_hole = num_hole4;
      num_current_hole_putts = num_hole4_putts;
    break;
    case 5:
      num_current_hole = num_hole5;
      num_current_hole_putts = num_hole5_putts;
    break;
    case 6:
      num_current_hole = num_hole6;
      num_current_hole_putts = num_hole6_putts;
    break;
    case 7:
      num_current_hole = num_hole7;
      num_current_hole_putts = num_hole7_putts;
    break;
    case 8:
      num_current_hole = num_hole8;
      num_current_hole_putts = num_hole8_putts;
    break;
    case 9:
      num_current_hole = num_hole9;
      num_current_hole_putts = num_hole9_putts;
    break;
    case 10:
      num_current_hole = num_hole10;
      num_current_hole_putts = num_hole10_putts;
    break;
    case 11:
      num_current_hole = num_hole11;
      num_current_hole_putts = num_hole11_putts;
    break;
    case 12:
      num_current_hole = num_hole12;
      num_current_hole_putts = num_hole12_putts;
    break;
    case 13:
      num_current_hole = num_hole13;
      num_current_hole_putts = num_hole13_putts;
    break;
    case 14:
      num_current_hole = num_hole14;
      num_current_hole_putts = num_hole14_putts;
    break;
    case 15:
      num_current_hole = num_hole15;
      num_current_hole_putts = num_hole15_putts;
    break;
    case 16:
      num_current_hole = num_hole16;
      num_current_hole_putts = num_hole16_putts;
    break;
    case 17:
      num_current_hole = num_hole17;
      num_current_hole_putts = num_hole17_putts;
    break;
    case 18:
      num_current_hole = num_hole18;
      num_current_hole_putts = num_hole18_putts;
    break;
  }
  
  update_text();
  
}

// creates a new round for the user to play
static void new_round(ClickRecognizerRef recognizer,void *context){
  
  	//Create an array of ON-OFF-ON etc durations in milliseconds
  uint32_t segments[] = {50, 150};

  //Create a VibePattern structure with the segments and length of the pattern as fields
  VibePattern pattern = {
    .durations = segments,
    .num_segments = ARRAY_LENGTH(segments),
  };

  //Trigger the custom pattern to be executed
  vibes_enqueue_custom_pattern(pattern);
  
  //window_stack_remove(window, true);
  new_round_confirmation_push();
  
}

// sets up the button interactions
static void click_config_provider(void *context) {
  const uint16_t repeat_interval_ms = 50;
  const uint16_t repeat_interval_ms1 = 700;
  
  window_single_repeating_click_subscribe(BUTTON_ID_UP, repeat_interval_ms, (ClickHandler) add_to_score);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, repeat_interval_ms, (ClickHandler) subtract_from_score);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, repeat_interval_ms, (ClickHandler) hole_forward);
  window_long_click_subscribe(BUTTON_ID_SELECT, repeat_interval_ms1, (ClickHandler) new_round, NULL);
  //window_long_click_subscribe(BUTTON_ID_DOWN, repeat_interval_ms1, (ClickHandler) course_overview, NULL);
  window_multi_click_subscribe(BUTTON_ID_SELECT, 2, 10, 0, true, hole_backwards);

  window_multi_click_subscribe(BUTTON_ID_UP, 2, 10, 0, true, (ClickHandler) add_putt_to_hole);
  window_multi_click_subscribe(BUTTON_ID_DOWN, 2, 10, 0, true, (ClickHandler) subtract_putt_from_hole);
}

// set up the view's window and layers
static void window_load(Window *me) {
  action_bar = action_bar_layer_create();
  action_bar_layer_add_to_window(action_bar, me);
  action_bar_layer_set_click_config_provider(action_bar, click_config_provider);

  action_bar_layer_set_icon(action_bar, BUTTON_ID_UP, action_icon_plus);
  action_bar_layer_set_icon(action_bar, BUTTON_ID_DOWN, action_icon_minus);
  action_bar_layer_set_icon(action_bar, BUTTON_ID_SELECT, action_icon_retry);

  Layer *layer = window_get_root_layer(me);
 
#if defined(PBL_RECT)
  
  header_text_layer = text_layer_create(GRect(1, 19, 114, 60));
  text_layer_set_font(header_text_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
  text_layer_set_background_color(header_text_layer, GColorClear);
  text_layer_set_text_alignment(header_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(header_text_layer, GColorWhite);
  layer_add_child(layer, text_layer_get_layer(header_text_layer));

  body_text_layer = text_layer_create(GRect(30, 60, 60, 49));
  text_layer_set_font(body_text_layer, fonts_get_system_font(FONT_KEY_LECO_38_BOLD_NUMBERS));
  text_layer_set_background_color(body_text_layer, GColorWhite);
  text_layer_set_text_alignment(body_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(body_text_layer, GColorJaegerGreen);
  layer_add_child(layer, text_layer_get_layer(body_text_layer));
  
  total_text_layer = text_layer_create(GRect(5, 130, 105, 35));
  text_layer_set_font(total_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  text_layer_set_background_color(total_text_layer, GColorWhite);
  text_layer_set_text_color(total_text_layer, GColorJaegerGreen);
  text_layer_set_text_alignment(total_text_layer, GTextAlignmentCenter);
  layer_add_child(layer, text_layer_get_layer(total_text_layer));

  label_text_layer = text_layer_create(GRect(2, 101, 114, 20));
  text_layer_set_font(label_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_background_color(label_text_layer, GColorClear);
  text_layer_set_text_color(label_text_layer, GColorBlack);
  text_layer_set_text_alignment(total_text_layer, GTextAlignmentCenter);
  text_layer_set_text(label_text_layer, "strokes on this hole");
  layer_add_child(layer, text_layer_get_layer(label_text_layer));
  
  // add putts layer
  putts_text_layer = text_layer_create(GRect(90, 60, 20, 49));
  text_layer_set_background_color(putts_text_layer, GColorWhite);
  text_layer_set_text_color(putts_text_layer, GColorJaegerGreen);
  text_layer_set_text(putts_text_layer, "0");
  text_layer_set_text_alignment(putts_text_layer, GTextAlignmentCenter);
  text_layer_set_font(putts_text_layer, fonts_get_system_font(FONT_KEY_LECO_20_BOLD_NUMBERS));
  layer_add_child(layer, text_layer_get_layer(putts_text_layer));

  printf("This is a rectangular display!");
  
#elif defined(PBL_ROUND)
  
  header_text_layer = text_layer_create(GRect(20, 30, 115, 60));
  text_layer_set_font(header_text_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
  layer_add_child(layer, text_layer_get_layer(header_text_layer));

  body_text_layer = text_layer_create(GRect(25, 72, 105, 50));
  text_layer_set_font(body_text_layer, fonts_get_system_font(FONT_KEY_LECO_38_BOLD_NUMBERS));
  layer_add_child(layer, text_layer_get_layer(body_text_layer));
  
  total_text_layer = text_layer_create(GRect(24, 156, 130, 60));
  text_layer_set_font(total_text_layer, fonts_get_system_font(FONT_KEY_LECO_20_BOLD_NUMBERS));
  layer_add_child(layer, text_layer_get_layer(total_text_layer));

  label_text_layer = text_layer_create(GRect(22, 120, 115, 60));
  text_layer_set_font(label_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text(label_text_layer, "strokes on this hole");
  layer_add_child(layer, text_layer_get_layer(label_text_layer));

#endif
  
#ifdef PBL_COLOR
  
  action_bar_layer_set_background_color(action_bar, GColorClear);
  
  text_layer_set_background_color(header_text_layer, GColorClear);
  text_layer_set_text_alignment(header_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(header_text_layer, GColorJaegerGreen);
  
  text_layer_set_background_color(body_text_layer, GColorJaegerGreen);
  text_layer_set_text_alignment(body_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(body_text_layer, GColorWhite);
  
  text_layer_set_background_color(total_text_layer, GColorJaegerGreen);
  text_layer_set_text_alignment(total_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(total_text_layer, GColorWhite);
  
  text_layer_set_background_color(label_text_layer, GColorClear);
  text_layer_set_text_color(label_text_layer, GColorJaegerGreen);

  text_layer_set_background_color(putts_text_layer, GColorJaegerGreen);
  text_layer_set_text_alignment(putts_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(putts_text_layer, GColorWhite);

  text_layer_set_background_color(teeaccuracy_text_layer, GColorJaegerGreen);
  text_layer_set_text_alignment(teeaccuracy_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(teeaccuracy_text_layer, GColorWhite);
  
  window_set_background_color(window, GColorMidnightGreen);
  
 #else
 
  action_bar_layer_set_background_color(action_bar, GColorLightGray);
  
  text_layer_set_background_color(header_text_layer, GColorClear);
  text_layer_set_text_alignment(header_text_layer, GTextAlignmentLeft);
  text_layer_set_text_color(header_text_layer, GColorWhite);
  
  text_layer_set_background_color(body_text_layer, GColorWhite);
  text_layer_set_text_alignment(body_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(body_text_layer, GColorBlack);
  
  text_layer_set_background_color(total_text_layer, GColorWhite);
  text_layer_set_text_alignment(total_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(total_text_layer, GColorBlack);
  
  text_layer_set_background_color(label_text_layer, GColorClear);
  text_layer_set_text_color(label_text_layer, GColorWhite);

  text_layer_set_background_color(putts_text_layer, GColorWhite);
  text_layer_set_text_alignment(putts_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(putts_text_layer, GColorBlack);
  
  text_layer_set_background_color(teeaccuracy_text_layer, GColorWhite);
  text_layer_set_text_alignment(teeaccuracy_text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(teeaccuracy_text_layer, GColorBlack);
  
  window_set_background_color(window, GColorBlack);
  
#endif
  
  // Create the StatusBarLayer
  s_status_bar = status_bar_layer_create();

  // Set properties
  status_bar_layer_set_colors(s_status_bar, GColorMidnightGreen, GColorWhite);
  status_bar_layer_set_separator_mode(s_status_bar, StatusBarLayerSeparatorModeDotted);

  // Add to Window
  layer_add_child(layer, status_bar_layer_get_layer(s_status_bar));
  
  update_text();
  
}

static void window_unload(Window *window) {
  text_layer_destroy(header_text_layer);
  text_layer_destroy(body_text_layer);
  text_layer_destroy(total_text_layer);
  text_layer_destroy(label_text_layer);
  text_layer_destroy(putts_text_layer);
  text_layer_destroy(teeaccuracy_text_layer);  

  action_bar_layer_destroy(action_bar);
  
  status_bar_layer_destroy(s_status_bar);
}

void window_save_scores(){
  
  // Save the count into persistent storage on app exit
  persist_write_int(NUM_CURRENT_HOLE_PKEY, num_current_hole);
  persist_write_int(NUM_TOTAL_PKEY, num_total);
  persist_write_int(NUM_HOLE_PKEY, num_hole);
  persist_write_int(NUM_HOLE1_PKEY, num_hole1);
  persist_write_int(NUM_HOLE2_PKEY, num_hole2);
  persist_write_int(NUM_HOLE3_PKEY, num_hole3);
  persist_write_int(NUM_HOLE4_PKEY, num_hole4);
  persist_write_int(NUM_HOLE5_PKEY, num_hole5);
  persist_write_int(NUM_HOLE6_PKEY, num_hole6);
  persist_write_int(NUM_HOLE7_PKEY, num_hole7);
  persist_write_int(NUM_HOLE8_PKEY, num_hole8);
  persist_write_int(NUM_HOLE9_PKEY, num_hole9);
  persist_write_int(NUM_HOLE10_PKEY, num_hole10);
  persist_write_int(NUM_HOLE11_PKEY, num_hole11);
  persist_write_int(NUM_HOLE12_PKEY, num_hole12);
  persist_write_int(NUM_HOLE13_PKEY, num_hole13);
  persist_write_int(NUM_HOLE14_PKEY, num_hole14);
  persist_write_int(NUM_HOLE15_PKEY, num_hole15);
  persist_write_int(NUM_HOLE16_PKEY, num_hole16);
  persist_write_int(NUM_HOLE17_PKEY, num_hole17);
  persist_write_int(NUM_HOLE18_PKEY, num_hole18);
  
  persist_write_int(NUM_CURRENT_HOLE_PUTTS_PKEY, num_current_hole_putts);
  persist_write_int(NUM_HOLE_PUTTS_PKEY, num_hole_putts);
  persist_write_int(NUM_HOLE1_PUTTS_PKEY, num_hole1_putts);
  persist_write_int(NUM_HOLE2_PUTTS_PKEY, num_hole2_putts);
  persist_write_int(NUM_HOLE3_PUTTS_PKEY, num_hole3_putts);
  persist_write_int(NUM_HOLE4_PUTTS_PKEY, num_hole4_putts);
  persist_write_int(NUM_HOLE5_PUTTS_PKEY, num_hole5_putts);
  persist_write_int(NUM_HOLE6_PUTTS_PKEY, num_hole6_putts);
  persist_write_int(NUM_HOLE7_PUTTS_PKEY, num_hole7_putts);
  persist_write_int(NUM_HOLE8_PUTTS_PKEY, num_hole8_putts);
  persist_write_int(NUM_HOLE9_PUTTS_PKEY, num_hole9_putts);
  persist_write_int(NUM_HOLE10_PUTTS_PKEY, num_hole10_putts);
  persist_write_int(NUM_HOLE11_PUTTS_PKEY, num_hole11_putts);
  persist_write_int(NUM_HOLE12_PUTTS_PKEY, num_hole12_putts);
  persist_write_int(NUM_HOLE13_PUTTS_PKEY, num_hole13_putts);
  persist_write_int(NUM_HOLE14_PUTTS_PKEY, num_hole14_putts);
  persist_write_int(NUM_HOLE15_PUTTS_PKEY, num_hole15_putts);
  persist_write_int(NUM_HOLE16_PUTTS_PKEY, num_hole16_putts);
  persist_write_int(NUM_HOLE17_PUTTS_PKEY, num_hole17_putts);
  persist_write_int(NUM_HOLE18_PUTTS_PKEY, num_hole18_putts);

  
}

void window_push(){

  // Get the count from persistent storage for use if it exists, otherwise use the default
  num_current_hole = persist_exists(NUM_CURRENT_HOLE_PKEY) ? persist_read_int(NUM_CURRENT_HOLE_PKEY) : NUM_CURRENT_HOLE_DEFAULT;
  num_total = persist_exists(NUM_TOTAL_PKEY) ? persist_read_int(NUM_TOTAL_PKEY) : NUM_TOTAL_DEFAULT;
  num_hole = persist_exists(NUM_HOLE_PKEY) ? persist_read_int(NUM_HOLE_PKEY) : NUM_HOLE_DEFAULT;
  num_hole1 = persist_exists(NUM_HOLE1_PKEY) ? persist_read_int(NUM_HOLE1_PKEY) : NUM_HOLE1_DEFAULT;
  num_hole2 = persist_exists(NUM_HOLE2_PKEY) ? persist_read_int(NUM_HOLE2_PKEY) : NUM_HOLE2_DEFAULT;
  num_hole3 = persist_exists(NUM_HOLE3_PKEY) ? persist_read_int(NUM_HOLE3_PKEY) : NUM_HOLE3_DEFAULT;
  num_hole4 = persist_exists(NUM_HOLE4_PKEY) ? persist_read_int(NUM_HOLE4_PKEY) : NUM_HOLE4_DEFAULT;
  num_hole5 = persist_exists(NUM_HOLE5_PKEY) ? persist_read_int(NUM_HOLE5_PKEY) : NUM_HOLE5_DEFAULT;
  num_hole6 = persist_exists(NUM_HOLE6_PKEY) ? persist_read_int(NUM_HOLE6_PKEY) : NUM_HOLE6_DEFAULT;
  num_hole7 = persist_exists(NUM_HOLE7_PKEY) ? persist_read_int(NUM_HOLE7_PKEY) : NUM_HOLE7_DEFAULT;
  num_hole8 = persist_exists(NUM_HOLE8_PKEY) ? persist_read_int(NUM_HOLE8_PKEY) : NUM_HOLE8_DEFAULT;
  num_hole9 = persist_exists(NUM_HOLE9_PKEY) ? persist_read_int(NUM_HOLE9_PKEY) : NUM_HOLE9_DEFAULT;
  num_hole10 = persist_exists(NUM_HOLE10_PKEY) ? persist_read_int(NUM_HOLE10_PKEY) : NUM_HOLE10_DEFAULT;
  num_hole11 = persist_exists(NUM_HOLE11_PKEY) ? persist_read_int(NUM_HOLE11_PKEY) : NUM_HOLE11_DEFAULT;
  num_hole12 = persist_exists(NUM_HOLE12_PKEY) ? persist_read_int(NUM_HOLE12_PKEY) : NUM_HOLE12_DEFAULT;
  num_hole13 = persist_exists(NUM_HOLE13_PKEY) ? persist_read_int(NUM_HOLE13_PKEY) : NUM_HOLE13_DEFAULT;
  num_hole14 = persist_exists(NUM_HOLE14_PKEY) ? persist_read_int(NUM_HOLE14_PKEY) : NUM_HOLE14_DEFAULT;
  num_hole15 = persist_exists(NUM_HOLE15_PKEY) ? persist_read_int(NUM_HOLE15_PKEY) : NUM_HOLE15_DEFAULT;
  num_hole16 = persist_exists(NUM_HOLE16_PKEY) ? persist_read_int(NUM_HOLE16_PKEY) : NUM_HOLE16_DEFAULT;
  num_hole17 = persist_exists(NUM_HOLE17_PKEY) ? persist_read_int(NUM_HOLE17_PKEY) : NUM_HOLE17_DEFAULT;
  num_hole18 = persist_exists(NUM_HOLE18_PKEY) ? persist_read_int(NUM_HOLE18_PKEY) : NUM_HOLE18_DEFAULT;
  
  num_current_hole_putts = persist_exists(NUM_CURRENT_HOLE_PUTTS_PKEY) ? persist_read_int(NUM_CURRENT_HOLE_PUTTS_PKEY) : NUM_CURRENT_HOLE_PUTTS_DEFAULT;
  num_hole_putts = persist_exists(NUM_HOLE_PUTTS_PKEY) ? persist_read_int(NUM_HOLE_PUTTS_PKEY) : NUM_HOLE_PUTTS_DEFAULT;
  num_hole1_putts = persist_exists(NUM_HOLE1_PUTTS_PKEY) ? persist_read_int(NUM_HOLE1_PUTTS_PKEY) : NUM_HOLE1_PUTTS_DEFAULT;
  num_hole2_putts = persist_exists(NUM_HOLE2_PUTTS_PKEY) ? persist_read_int(NUM_HOLE2_PUTTS_PKEY) : NUM_HOLE2_PUTTS_DEFAULT;
  num_hole3_putts = persist_exists(NUM_HOLE3_PUTTS_PKEY) ? persist_read_int(NUM_HOLE3_PUTTS_PKEY) : NUM_HOLE3_PUTTS_DEFAULT;
  num_hole4_putts = persist_exists(NUM_HOLE4_PUTTS_PKEY) ? persist_read_int(NUM_HOLE4_PUTTS_PKEY) : NUM_HOLE4_PUTTS_DEFAULT;
  num_hole5_putts = persist_exists(NUM_HOLE5_PUTTS_PKEY) ? persist_read_int(NUM_HOLE5_PUTTS_PKEY) : NUM_HOLE5_PUTTS_DEFAULT;
  num_hole6_putts = persist_exists(NUM_HOLE6_PUTTS_PKEY) ? persist_read_int(NUM_HOLE6_PUTTS_PKEY) : NUM_HOLE6_PUTTS_DEFAULT;
  num_hole7_putts = persist_exists(NUM_HOLE7_PUTTS_PKEY) ? persist_read_int(NUM_HOLE7_PUTTS_PKEY) : NUM_HOLE7_PUTTS_DEFAULT;
  num_hole8_putts = persist_exists(NUM_HOLE8_PUTTS_PKEY) ? persist_read_int(NUM_HOLE8_PUTTS_PKEY) : NUM_HOLE8_PUTTS_DEFAULT;
  num_hole9_putts = persist_exists(NUM_HOLE9_PUTTS_PKEY) ? persist_read_int(NUM_HOLE9_PUTTS_PKEY) : NUM_HOLE9_PUTTS_DEFAULT;
  num_hole10_putts = persist_exists(NUM_HOLE10_PUTTS_PKEY) ? persist_read_int(NUM_HOLE10_PUTTS_PKEY) : NUM_HOLE10_PUTTS_DEFAULT;
  num_hole11_putts = persist_exists(NUM_HOLE11_PUTTS_PKEY) ? persist_read_int(NUM_HOLE11_PUTTS_PKEY) : NUM_HOLE11_PUTTS_DEFAULT;
  num_hole12_putts = persist_exists(NUM_HOLE12_PUTTS_PKEY) ? persist_read_int(NUM_HOLE12_PUTTS_PKEY) : NUM_HOLE12_PUTTS_DEFAULT;
  num_hole13_putts = persist_exists(NUM_HOLE13_PUTTS_PKEY) ? persist_read_int(NUM_HOLE13_PUTTS_PKEY) : NUM_HOLE13_PUTTS_DEFAULT;
  num_hole14_putts = persist_exists(NUM_HOLE14_PUTTS_PKEY) ? persist_read_int(NUM_HOLE14_PUTTS_PKEY) : NUM_HOLE14_PUTTS_DEFAULT;
  num_hole15_putts = persist_exists(NUM_HOLE15_PUTTS_PKEY) ? persist_read_int(NUM_HOLE15_PUTTS_PKEY) : NUM_HOLE15_PUTTS_DEFAULT;
  num_hole16_putts = persist_exists(NUM_HOLE16_PUTTS_PKEY) ? persist_read_int(NUM_HOLE16_PUTTS_PKEY) : NUM_HOLE16_PUTTS_DEFAULT;
  num_hole17_putts = persist_exists(NUM_HOLE17_PUTTS_PKEY) ? persist_read_int(NUM_HOLE17_PUTTS_PKEY) : NUM_HOLE17_PUTTS_DEFAULT;
  num_hole18_putts = persist_exists(NUM_HOLE18_PUTTS_PKEY) ? persist_read_int(NUM_HOLE18_PUTTS_PKEY) : NUM_HOLE18_PUTTS_DEFAULT;

  
  
  update_text();

}

static void init(void) {
  action_icon_plus = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_PLUS);
  action_icon_minus = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_MINUS);
  action_icon_retry = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ACTION_ICON_RETRY);

  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  
   // Get the count from persistent storage for use if it exists, otherwise use the default
  num_current_hole = persist_exists(NUM_CURRENT_HOLE_PKEY) ? persist_read_int(NUM_CURRENT_HOLE_PKEY) : NUM_CURRENT_HOLE_DEFAULT;
  num_total = persist_exists(NUM_TOTAL_PKEY) ? persist_read_int(NUM_TOTAL_PKEY) : NUM_TOTAL_DEFAULT;
  num_hole = persist_exists(NUM_HOLE_PKEY) ? persist_read_int(NUM_HOLE_PKEY) : NUM_HOLE_DEFAULT;
  num_hole1 = persist_exists(NUM_HOLE1_PKEY) ? persist_read_int(NUM_HOLE1_PKEY) : NUM_HOLE1_DEFAULT;
  num_hole2 = persist_exists(NUM_HOLE2_PKEY) ? persist_read_int(NUM_HOLE2_PKEY) : NUM_HOLE2_DEFAULT;
  num_hole3 = persist_exists(NUM_HOLE3_PKEY) ? persist_read_int(NUM_HOLE3_PKEY) : NUM_HOLE3_DEFAULT;
  num_hole4 = persist_exists(NUM_HOLE4_PKEY) ? persist_read_int(NUM_HOLE4_PKEY) : NUM_HOLE4_DEFAULT;
  num_hole5 = persist_exists(NUM_HOLE5_PKEY) ? persist_read_int(NUM_HOLE5_PKEY) : NUM_HOLE5_DEFAULT;
  num_hole6 = persist_exists(NUM_HOLE6_PKEY) ? persist_read_int(NUM_HOLE6_PKEY) : NUM_HOLE6_DEFAULT;
  num_hole7 = persist_exists(NUM_HOLE7_PKEY) ? persist_read_int(NUM_HOLE7_PKEY) : NUM_HOLE7_DEFAULT;
  num_hole8 = persist_exists(NUM_HOLE8_PKEY) ? persist_read_int(NUM_HOLE8_PKEY) : NUM_HOLE8_DEFAULT;
  num_hole9 = persist_exists(NUM_HOLE9_PKEY) ? persist_read_int(NUM_HOLE9_PKEY) : NUM_HOLE9_DEFAULT;
  num_hole10 = persist_exists(NUM_HOLE10_PKEY) ? persist_read_int(NUM_HOLE10_PKEY) : NUM_HOLE10_DEFAULT;
  num_hole11 = persist_exists(NUM_HOLE11_PKEY) ? persist_read_int(NUM_HOLE11_PKEY) : NUM_HOLE11_DEFAULT;
  num_hole12 = persist_exists(NUM_HOLE12_PKEY) ? persist_read_int(NUM_HOLE12_PKEY) : NUM_HOLE12_DEFAULT;
  num_hole13 = persist_exists(NUM_HOLE13_PKEY) ? persist_read_int(NUM_HOLE13_PKEY) : NUM_HOLE13_DEFAULT;
  num_hole14 = persist_exists(NUM_HOLE14_PKEY) ? persist_read_int(NUM_HOLE14_PKEY) : NUM_HOLE14_DEFAULT;
  num_hole15 = persist_exists(NUM_HOLE15_PKEY) ? persist_read_int(NUM_HOLE15_PKEY) : NUM_HOLE15_DEFAULT;
  num_hole16 = persist_exists(NUM_HOLE16_PKEY) ? persist_read_int(NUM_HOLE16_PKEY) : NUM_HOLE16_DEFAULT;
  num_hole17 = persist_exists(NUM_HOLE17_PKEY) ? persist_read_int(NUM_HOLE17_PKEY) : NUM_HOLE17_DEFAULT;
  num_hole18 = persist_exists(NUM_HOLE18_PKEY) ? persist_read_int(NUM_HOLE18_PKEY) : NUM_HOLE18_DEFAULT;
  
  num_current_hole_putts = persist_exists(NUM_CURRENT_HOLE_PUTTS_PKEY) ? persist_read_int(NUM_CURRENT_HOLE_PUTTS_PKEY) : NUM_CURRENT_HOLE_PUTTS_DEFAULT;
  num_hole_putts = persist_exists(NUM_HOLE_PUTTS_PKEY) ? persist_read_int(NUM_HOLE_PUTTS_PKEY) : NUM_HOLE_PUTTS_DEFAULT;
  num_hole1_putts = persist_exists(NUM_HOLE1_PUTTS_PKEY) ? persist_read_int(NUM_HOLE1_PUTTS_PKEY) : NUM_HOLE1_PUTTS_DEFAULT;
  num_hole2_putts = persist_exists(NUM_HOLE2_PUTTS_PKEY) ? persist_read_int(NUM_HOLE2_PUTTS_PKEY) : NUM_HOLE2_PUTTS_DEFAULT;
  num_hole3_putts = persist_exists(NUM_HOLE3_PUTTS_PKEY) ? persist_read_int(NUM_HOLE3_PUTTS_PKEY) : NUM_HOLE3_PUTTS_DEFAULT;
  num_hole4_putts = persist_exists(NUM_HOLE4_PUTTS_PKEY) ? persist_read_int(NUM_HOLE4_PUTTS_PKEY) : NUM_HOLE4_PUTTS_DEFAULT;
  num_hole5_putts = persist_exists(NUM_HOLE5_PUTTS_PKEY) ? persist_read_int(NUM_HOLE5_PUTTS_PKEY) : NUM_HOLE5_PUTTS_DEFAULT;
  num_hole6_putts = persist_exists(NUM_HOLE6_PUTTS_PKEY) ? persist_read_int(NUM_HOLE6_PUTTS_PKEY) : NUM_HOLE6_PUTTS_DEFAULT;
  num_hole7_putts = persist_exists(NUM_HOLE7_PUTTS_PKEY) ? persist_read_int(NUM_HOLE7_PUTTS_PKEY) : NUM_HOLE7_PUTTS_DEFAULT;
  num_hole8_putts = persist_exists(NUM_HOLE8_PUTTS_PKEY) ? persist_read_int(NUM_HOLE8_PUTTS_PKEY) : NUM_HOLE8_PUTTS_DEFAULT;
  num_hole9_putts = persist_exists(NUM_HOLE9_PUTTS_PKEY) ? persist_read_int(NUM_HOLE9_PUTTS_PKEY) : NUM_HOLE9_PUTTS_DEFAULT;
  num_hole10_putts = persist_exists(NUM_HOLE10_PUTTS_PKEY) ? persist_read_int(NUM_HOLE10_PUTTS_PKEY) : NUM_HOLE10_PUTTS_DEFAULT;
  num_hole11_putts = persist_exists(NUM_HOLE11_PUTTS_PKEY) ? persist_read_int(NUM_HOLE11_PUTTS_PKEY) : NUM_HOLE11_PUTTS_DEFAULT;
  num_hole12_putts = persist_exists(NUM_HOLE12_PUTTS_PKEY) ? persist_read_int(NUM_HOLE12_PUTTS_PKEY) : NUM_HOLE12_PUTTS_DEFAULT;
  num_hole13_putts = persist_exists(NUM_HOLE13_PUTTS_PKEY) ? persist_read_int(NUM_HOLE13_PUTTS_PKEY) : NUM_HOLE13_PUTTS_DEFAULT;
  num_hole14_putts = persist_exists(NUM_HOLE14_PUTTS_PKEY) ? persist_read_int(NUM_HOLE14_PUTTS_PKEY) : NUM_HOLE14_PUTTS_DEFAULT;
  num_hole15_putts = persist_exists(NUM_HOLE15_PUTTS_PKEY) ? persist_read_int(NUM_HOLE15_PUTTS_PKEY) : NUM_HOLE15_PUTTS_DEFAULT;
  num_hole16_putts = persist_exists(NUM_HOLE16_PUTTS_PKEY) ? persist_read_int(NUM_HOLE16_PUTTS_PKEY) : NUM_HOLE16_PUTTS_DEFAULT;
  num_hole17_putts = persist_exists(NUM_HOLE17_PUTTS_PKEY) ? persist_read_int(NUM_HOLE17_PUTTS_PKEY) : NUM_HOLE17_PUTTS_DEFAULT;
  num_hole18_putts = persist_exists(NUM_HOLE18_PUTTS_PKEY) ? persist_read_int(NUM_HOLE18_PUTTS_PKEY) : NUM_HOLE18_PUTTS_DEFAULT;

  
  window_stack_push(window,true);
}

static void deinit(void){
  
  window_destroy(window);
  
  // Save the count into persistent storage on app exit
  persist_write_int(NUM_CURRENT_HOLE_PKEY, num_current_hole);
  persist_write_int(NUM_TOTAL_PKEY, num_total);
  persist_write_int(NUM_HOLE_PKEY, num_hole);
  persist_write_int(NUM_HOLE1_PKEY, num_hole1);
  persist_write_int(NUM_HOLE2_PKEY, num_hole2);
  persist_write_int(NUM_HOLE3_PKEY, num_hole3);
  persist_write_int(NUM_HOLE4_PKEY, num_hole4);
  persist_write_int(NUM_HOLE5_PKEY, num_hole5);
  persist_write_int(NUM_HOLE6_PKEY, num_hole6);
  persist_write_int(NUM_HOLE7_PKEY, num_hole7);
  persist_write_int(NUM_HOLE8_PKEY, num_hole8);
  persist_write_int(NUM_HOLE9_PKEY, num_hole9);
  persist_write_int(NUM_HOLE10_PKEY, num_hole10);
  persist_write_int(NUM_HOLE11_PKEY, num_hole11);
  persist_write_int(NUM_HOLE12_PKEY, num_hole12);
  persist_write_int(NUM_HOLE13_PKEY, num_hole13);
  persist_write_int(NUM_HOLE14_PKEY, num_hole14);
  persist_write_int(NUM_HOLE15_PKEY, num_hole15);
  persist_write_int(NUM_HOLE16_PKEY, num_hole16);
  persist_write_int(NUM_HOLE17_PKEY, num_hole17);
  persist_write_int(NUM_HOLE18_PKEY, num_hole18);

  persist_write_int(NUM_CURRENT_HOLE_PUTTS_PKEY, num_current_hole_putts);
  persist_write_int(NUM_HOLE_PUTTS_PKEY, num_hole_putts);
  persist_write_int(NUM_HOLE1_PUTTS_PKEY, num_hole1_putts);
  persist_write_int(NUM_HOLE2_PUTTS_PKEY, num_hole2_putts);
  persist_write_int(NUM_HOLE3_PUTTS_PKEY, num_hole3_putts);
  persist_write_int(NUM_HOLE4_PUTTS_PKEY, num_hole4_putts);
  persist_write_int(NUM_HOLE5_PUTTS_PKEY, num_hole5_putts);
  persist_write_int(NUM_HOLE6_PUTTS_PKEY, num_hole6_putts);
  persist_write_int(NUM_HOLE7_PUTTS_PKEY, num_hole7_putts);
  persist_write_int(NUM_HOLE8_PUTTS_PKEY, num_hole8_putts);
  persist_write_int(NUM_HOLE9_PUTTS_PKEY, num_hole9_putts);
  persist_write_int(NUM_HOLE10_PUTTS_PKEY, num_hole10_putts);
  persist_write_int(NUM_HOLE11_PUTTS_PKEY, num_hole11_putts);
  persist_write_int(NUM_HOLE12_PUTTS_PKEY, num_hole12_putts);
  persist_write_int(NUM_HOLE13_PUTTS_PKEY, num_hole13_putts);
  persist_write_int(NUM_HOLE14_PUTTS_PKEY, num_hole14_putts);
  persist_write_int(NUM_HOLE15_PUTTS_PKEY, num_hole15_putts);
  persist_write_int(NUM_HOLE16_PUTTS_PKEY, num_hole16_putts);
  persist_write_int(NUM_HOLE17_PUTTS_PKEY, num_hole17_putts);
  persist_write_int(NUM_HOLE18_PUTTS_PKEY, num_hole18_putts);
  
  gbitmap_destroy(action_icon_plus);
  gbitmap_destroy(action_icon_minus);
  gbitmap_destroy(action_icon_retry);
  
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
