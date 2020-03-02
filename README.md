# 5x7_led_matrix

#Functions are given below

#glow_led()
To glow a perticular led just pass the number as an argument to this function.
Example - glow_led(3)

#off_led()
To off a perticular led just pass the number as an argument to this function.
Example - off_led(3)

#glow_all()
This function will make all the leds to glow.

#off_all()
This function turn off all the leds.

#disp_char()
pass any character in disp_char() function to display it on the led matrix.
Example - disp_char('J') 
Note - Only caps characters are supported.

#disp_custom_char()
pass array of custom character created. 
Example - 

int my_custom_char[7][5] = {
							  {0, 0, 1, 0, 0},
							  {0, 1, 1, 1, 0},
							  {1, 0, 1, 0, 1},
							  {0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0},
							  {0, 0, 1, 0, 0}
							};
							
disp_custom_char(my_custom_char);
							
Note - Only caps characters are supported.

#disp_char_scroll()
pass any character in disp_char_scroll() function to display it on the led matrix in scrolling pattern.
Example - disp_char_scroll('J') 
Note - Only caps characters are supported.
