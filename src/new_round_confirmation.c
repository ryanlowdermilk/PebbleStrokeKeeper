#ifdef PBL_COLOR
  
#include <pebble.h>
#include "new_round_confirmation.h"
#include "main.h"

static Window *s_main_window;
static TextLayer *s_label_layer;
static BitmapLayer *s_icon_layer;
static ActionBarLayer *s_action_bar_layer;

static GBitmap *s_icon_bitmap, *s_tick_bitmap, *s_cross_bitmap;

static void reset_score(ClickRecognizerRef recognizer,void *context){
  
  num_hole=1;
  num_total=0;
  num_current_hole=0;
  
  num_hole1=0;
  num_hole2=0;
  num_hole3=0;
  num_hole4=0;
  num_hole5=0;
  num_hole6=0;
  num_hole7=0;
  num_hole8=0;
  num_hole9=0;
  num_hole10=0;
  num_hole11=0;
  num_hole12=0;
  num_hole13=0;
  num_hole14=0;
  num_hole15=0;
  num_hole16=0;
  num_hole17=0;
  num_hole18=0;
  num_hole1_putts=0;
  num_hole2_putts=0;
  num_hole3_putts=0;
  num_hole4_putts=0;
  num_hole5_putts=0;
  num_hole6_putts=0;
  num_hole7_putts=0;
  num_hole8_putts=0;
  num_hole9_putts=0;
  num_hole10_putts=0;
  num_hole11_putts=0;
  num_hole12_putts=0;
  num_hole13_putts=0;
  num_hole14_putts=0;
  num_hole15_putts=0;
  num_hole16_putts=0;
  num_hole17_putts=0;
  num_hole18_putts=0;  
 
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



  
  
  //Create an array of ON-OFF-ON etc durations in milliseconds
  uint32_t segments[] = {100, 200, 100, 250};

  //Create a VibePattern structure with the segments and length of the pattern as fields
 VibePattern pattern = {
    .durations = segments,
    .num_segments = ARRAY_LENGTH(segments),
  };

  //Trigger the custom pattern to be executed
  vibes_enqueue_custom_pattern(pattern);
  
  window_push();
  window_stack_remove(s_main_window,true);
  
}

static void exit_click_handler(ClickRecognizerRef recognizer, void *context){
  
  uint32_t segments[] = {100};

  //Create a VibePattern structure with the segments and length of the pattern as fields
 VibePattern pattern = {
    .durations = segments,
    .num_segments = ARRAY_LENGTH(segments),
  };

  //Trigger the custom pattern to be executed
  vibes_enqueue_custom_pattern(pattern);
  
 // window_stack_remove(s_main_window,true);
  window_stack_remove(s_main_window,true);

}

static void click_config_provider(void *context){
  
  const uint16_t repeat_interval_ms = 50;
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN,repeat_interval_ms, (ClickHandler) exit_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_UP, repeat_interval_ms, (ClickHandler) reset_score);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_icon_bitmap = gbitmap_create_with_resource(RESOURCE_ID_WARNING);
  GRect bitmap_bounds = gbitmap_get_bounds(s_icon_bitmap);

  #if defined(PBL_RECT)
  printf("This is a rectangular display!");

  s_icon_layer = bitmap_layer_create(GRect((bounds.size.w / 2) - (bitmap_bounds.size.w / 2) - (ACTION_BAR_WIDTH / 2), 10, bitmap_bounds.size.w, bitmap_bounds.size.h));
  bitmap_layer_set_bitmap(s_icon_layer, s_icon_bitmap);
  bitmap_layer_set_compositing_mode(s_icon_layer, GCompOpSet);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_icon_layer));

  s_label_layer = text_layer_create(GRect(10, 10 + bitmap_bounds.size.h + 5, 124 - ACTION_BAR_WIDTH, bounds.size.h - (10 + bitmap_bounds.size.h + 15)));
  text_layer_set_text(s_label_layer, DIALOG_CHOICE_WINDOW_MESSAGE);
  text_layer_set_background_color(s_label_layer, GColorClear);
  text_layer_set_text_color(s_label_layer, GColorWhite);
  text_layer_set_text_alignment(s_label_layer, GTextAlignmentCenter);
  text_layer_set_font(s_label_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  layer_add_child(window_layer, text_layer_get_layer(s_label_layer));
#elif defined(PBL_ROUND)
  printf("This is a round display!");
  
   s_icon_layer = bitmap_layer_create(GRect(70, 10, bitmap_bounds.size.w, bitmap_bounds.size.h));
  bitmap_layer_set_bitmap(s_icon_layer, s_icon_bitmap);
  bitmap_layer_set_compositing_mode(s_icon_layer, GCompOpSet);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_icon_layer));

  s_label_layer = text_layer_create(GRect(40, 10 + bitmap_bounds.size.h + 5, 124 - ACTION_BAR_WIDTH, bounds.size.h - (10 + bitmap_bounds.size.h + 15)));
  text_layer_set_text(s_label_layer, DIALOG_CHOICE_WINDOW_MESSAGE);
  text_layer_set_background_color(s_label_layer, GColorClear);
  text_layer_set_text_color(s_label_layer, GColorWhite);
  text_layer_set_text_alignment(s_label_layer, GTextAlignmentCenter);
  text_layer_set_font(s_label_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  layer_add_child(window_layer, text_layer_get_layer(s_label_layer));
#endif
  
  
  s_tick_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TICK);
  s_cross_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CROSS);

  s_action_bar_layer = action_bar_layer_create();
  action_bar_layer_set_icon(s_action_bar_layer, BUTTON_ID_UP, s_tick_bitmap);
  action_bar_layer_set_icon(s_action_bar_layer, BUTTON_ID_DOWN, s_cross_bitmap);
  action_bar_layer_add_to_window(s_action_bar_layer, window);
  action_bar_layer_set_click_config_provider(s_action_bar_layer, click_config_provider);
}

static void window_unload(Window *window) {
  text_layer_destroy(s_label_layer);
  action_bar_layer_destroy(s_action_bar_layer);
  bitmap_layer_destroy(s_icon_layer);

  gbitmap_destroy(s_icon_bitmap); 
  gbitmap_destroy(s_tick_bitmap);
  gbitmap_destroy(s_cross_bitmap);
  
  window_destroy(window);
  s_main_window = NULL;
}

void new_round_confirmation_push() {
  if(!s_main_window) {
    s_main_window = window_create();
    window_set_background_color(s_main_window, GColorRed);
    window_set_window_handlers(s_main_window, (WindowHandlers) {
        .load = window_load,
        .unload = window_unload,
    });
  }
  
  window_stack_push(s_main_window, true);
}

#else

#include <pebble.h>
#include "new_round_confirmation.h"
#include "main.h"

static Window *s_main_window;
static TextLayer *s_label_layer;
static BitmapLayer *s_icon_layer;
static ActionBarLayer *s_action_bar_layer;

static GBitmap *s_icon_bitmap, *s_tick_bitmap, *s_cross_bitmap;

static void reset_score(ClickRecognizerRef recognizer,void *context){
  
  num_hole=1;
  num_total=0;
  num_current_hole=0;
  
  num_hole1=0;
  num_hole2=0;
  num_hole3=0;
  num_hole4=0;
  num_hole5=0;
  num_hole6=0;
  num_hole7=0;
  num_hole8=0;
  num_hole9=0;
  num_hole10=0;
  num_hole11=0;
  num_hole12=0;
  num_hole13=0;
  num_hole14=0;
  num_hole15=0;
  num_hole16=0;
  num_hole17=0;
  num_hole18=0;
  num_hole1_putts=0;
  num_hole2_putts=0;
  num_hole3_putts=0;
  num_hole4_putts=0;
  num_hole5_putts=0;
  num_hole6_putts=0;
  num_hole7_putts=0;
  num_hole8_putts=0;
  num_hole9_putts=0;
  num_hole10_putts=0;
  num_hole11_putts=0;
  num_hole12_putts=0;
  num_hole13_putts=0;
  num_hole14_putts=0;
  num_hole15_putts=0;
  num_hole16_putts=0;
  num_hole17_putts=0;
  num_hole18_putts=0;
 
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



  
  
  //Create an array of ON-OFF-ON etc durations in milliseconds
  uint32_t segments[] = {100, 200, 100, 250};

  //Create a VibePattern structure with the segments and length of the pattern as fields
 VibePattern pattern = {
    .durations = segments,
    .num_segments = ARRAY_LENGTH(segments),
  };

  //Trigger the custom pattern to be executed
  vibes_enqueue_custom_pattern(pattern);
  
  window_push();
  window_stack_remove(s_main_window,true);
  
}

static void exit_click_handler(ClickRecognizerRef recognizer, void *context){
  
  uint32_t segments[] = {100};

  //Create a VibePattern structure with the segments and length of the pattern as fields
 VibePattern pattern = {
    .durations = segments,
    .num_segments = ARRAY_LENGTH(segments),
  };

  //Trigger the custom pattern to be executed
  vibes_enqueue_custom_pattern(pattern);
  
 // window_stack_remove(s_main_window,true);
  window_stack_remove(s_main_window,true);

}

static void click_config_provider(void *context){
  
  const uint16_t repeat_interval_ms = 50;
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN,repeat_interval_ms, (ClickHandler) exit_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_UP, repeat_interval_ms, (ClickHandler) reset_score);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  s_icon_bitmap = gbitmap_create_with_resource(RESOURCE_ID_WARNING);
  GRect bitmap_bounds = gbitmap_get_bounds(s_icon_bitmap);

  s_icon_layer = bitmap_layer_create(GRect((bounds.size.w / 2) - (bitmap_bounds.size.w / 2) - (ACTION_BAR_WIDTH / 2), 10, bitmap_bounds.size.w, bitmap_bounds.size.h));
  bitmap_layer_set_bitmap(s_icon_layer, s_icon_bitmap);
  bitmap_layer_set_compositing_mode(s_icon_layer, GCompOpSet);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_icon_layer));

  s_label_layer = text_layer_create(GRect(10, 10 + bitmap_bounds.size.h + 5, 124 - ACTION_BAR_WIDTH, bounds.size.h - (10 + bitmap_bounds.size.h + 15)));
  text_layer_set_text(s_label_layer, DIALOG_CHOICE_WINDOW_MESSAGE);
  text_layer_set_background_color(s_label_layer, GColorClear);
  text_layer_set_text_color(s_label_layer, GColorWhite);
  text_layer_set_text_alignment(s_label_layer, GTextAlignmentCenter);
  text_layer_set_font(s_label_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  layer_add_child(window_layer, text_layer_get_layer(s_label_layer));

  s_tick_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CHECK);
  s_cross_bitmap = gbitmap_create_with_resource(RESOURCE_ID_EXIT);

  s_action_bar_layer = action_bar_layer_create();
  action_bar_layer_set_icon(s_action_bar_layer, BUTTON_ID_UP, s_tick_bitmap);
  action_bar_layer_set_icon(s_action_bar_layer, BUTTON_ID_DOWN, s_cross_bitmap);
  action_bar_layer_add_to_window(s_action_bar_layer, window);
  action_bar_layer_set_background_color(s_action_bar_layer, GColorWhite);
  action_bar_layer_set_click_config_provider(s_action_bar_layer, click_config_provider);
}

static void window_unload(Window *window) {
  text_layer_destroy(s_label_layer);
  action_bar_layer_destroy(s_action_bar_layer);
  bitmap_layer_destroy(s_icon_layer);

  gbitmap_destroy(s_icon_bitmap); 
  gbitmap_destroy(s_tick_bitmap);
  gbitmap_destroy(s_cross_bitmap);
  
  window_destroy(window);
  s_main_window = NULL;
}

void new_round_confirmation_push() {
  if(!s_main_window) {
    s_main_window = window_create();
    window_set_background_color(s_main_window, GColorBlack);
    window_set_window_handlers(s_main_window, (WindowHandlers) {
        .load = window_load,
        .unload = window_unload,
    });
  }
  
  window_stack_push(s_main_window, true);
}

#endif