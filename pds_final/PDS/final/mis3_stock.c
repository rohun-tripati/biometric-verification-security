// the one where the supply shows tables and u can update into how much u got
// come here after clearign authentication on supplier page
// goes to supp3 show_frame_supp3 wher shopkeeper's authentication is taken
// components tabels
// comes from sup1_auth.c

#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
#include<pwrap2.h>

#include <fcntl.h>
#include <sys/stat.h>

#include"features_live.h"

#ifdef __arm__
#include <biometric.h>
#endif

int amount[3];
pw_widget toplevel, mis3_screen ,mis3_butt_back, mis3_butt_submit;
pw_widget mis3_label[3], mis3_combo; //may be used
pw_widget mis3_lbox_stock;

void show_frame_home();
void show_frame_mis2();
int exec_query_load_into_lbox_trriple(pw_widget lbox, char *query, char *database);

void mis3_hide_screen()
{
	pw_hide(mis3_screen);
}
void mis3_home_cb()
{
	mis3_hide_screen();
	show_frame_home();
	return;
}
void mis3_back_cb()
{
	mis3_hide_screen();
	show_frame_mis2();
	return;
}
void show_frame_mis3()
{

//page graphics begin
	mis3_screen = pw_create_frame(toplevel,0, 40, 240, 230,
                        PW_BGCOLOR, LTGOLD ,
                        PW_CONFIG_END);

	mis3_label[0] = pw_create_label(mis3_screen, 15, 10, 200, 40,
			PW_TEXT,"Quantity Of Products In Stock: ",
			PW_FONT, PW_BOLD_FONT,
			//PW_BORDER, PW_RECTANGLE_BORDER,
			//PW_CALLBACK, PW_BUTTON_RELEASE_EVENT,cb_alocfrm_date,
			PW_FGCOLOR, "BLACK",
			PW_BGCOLOR, LTGOLD,
			PW_CONFIG_END);

	mis3_lbox_stock =pw_create_tlistbox(mis3_screen, 0, 50 , 240, 80,
			PW_BGCOLOR, "#F5DEBC",
			PW_FONT, PW_BOLD_FONT,
			PW_CONFIG_END);
	pw_tlistbox_addcolumn(mis3_lbox_stock,80);
	pw_tlistbox_addcolumn(mis3_lbox_stock,80);
	pw_tlistbox_addcolumn(mis3_lbox_stock,80);
	pw_update(mis3_lbox_stock,1);
//sqlite stuff
	char query[1024];
	pw_tlistbox_clear(mis3_lbox_stock);

	sprintf(query,"select product,code, quantity from stock ");
	exec_query_load_into_lbox_trriple(mis3_lbox_stock,query, DB_PACK);
	pw_update(mis3_lbox_stock,1);

///////sqlite stuff ends
	
	mis3_butt_back = pw_create_button(mis3_screen, 15, 180, 80,20,
                        PW_ACTIVE_IMAGE, "/root/PDS/back.png",
                        PW_NORMAL_IMAGE, "/root/PDS/back.png",
                        PW_CALLBACK, PW_BUTTON_RELEASE_EVENT, mis3_back_cb,
                        PW_CONFIG_END);
	mis3_butt_submit = pw_create_button(mis3_screen, 110, 180, 80,20,
                        PW_ACTIVE_IMAGE, "/root/PDS/home.png",
                        PW_NORMAL_IMAGE, "/root/PDS/home.png",
                        PW_CALLBACK, PW_BUTTON_RELEASE_EVENT, mis3_home_cb,
                        PW_CONFIG_END);	
	
	mis3_label[1] = pw_create_label(mis3_screen, 20, 270, 120, 40,
			PW_TEXT,"",
			PW_FONT, PW_BOLD_FONT,
			//PW_BORDER, PW_RECTANGLE_BORDER,
			//PW_CALLBACK, PW_BUTTON_RELEASE_EVENT,cb_alocfrm_date,
			PW_FGCOLOR, "BLACK",
			PW_BGCOLOR, LTGOLD,
			PW_CONFIG_END);
	return ;
}
