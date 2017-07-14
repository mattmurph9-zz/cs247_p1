#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm.h>
#include <vector>

class GameWindow : public Gtk::Window {
public:
	GameWindow();
	GameWindow(BaseObjectType* w, const Glib::RefPtr<Gtk::Builder>& builder);
	virtual ~GameWindow();

protected:
  //Signal handlers:
	void on_file_new();
	void on_file_new_seed();
	void on_file_quit();
	void on_player_ragequit(int player);

	Gtk::MenuItem* m_pNew;
	Gtk::MenuItem* m_pNewSeed;
	Gtk::MenuItem* m_pQuit;
	std::vector<Gtk::Button*> m_pRqButtons;
	Glib::RefPtr<Gtk::Builder> m_refGlade;
};

#endif //GTKMM_GAMEWINDOW_H