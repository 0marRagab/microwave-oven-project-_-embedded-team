case 'A':
				lcd_clear();
				lcd_setCursor(5,1);                    // call lcd_goto(col,row) to set cursor at specific location
				lcd_print("Popcorn");
				delay_ms(2000);
			  lcd_clear();
				lcd_setCursor(1,1);
		    lcd_print ("EN s2 to start");
				while(sw2_in()==0){}
				lcd_clear();
				lcd_setCursor(5,1);                    // call lcd_goto(col,row) to set cursor at specific location
				lcd_print("Popcorn");
				lcd_timer("0059");
				break;
