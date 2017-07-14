#ifndef GTKMM_PLAYERDIALOG_H
#define GTKMM_PLAYERDIALOG_H

#include <gtkmm.h>

class PlayerDialog : public Gtk::Dialog {
public:
	PlayerDialog();
	PlayerDialog(BaseObjectType* w, const Glib::RefPtr<Gtk::Builder>& builder);
	virtual ~PlayerDialog();

protected:
  //Signal handlers:
	void on_computer();
	void on_human();

	Gtk::Button* m_pHuman;
	Gtk::Button* m_pComputer;
	Glib::RefPtr<Gtk::Builder> m_refGlade;
};

#endif //GTKMM_GAMEWINDOW_H