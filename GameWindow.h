#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm.h>

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

	Gtk::MenuItem* m_pNew;
	Gtk::MenuItem* m_pNewSeed;
	Gtk::MenuItem* m_pQuit;
	Glib::RefPtr<Gtk::Builder> m_refGlade;
};

#endif //GTKMM_GAMEWINDOW_H