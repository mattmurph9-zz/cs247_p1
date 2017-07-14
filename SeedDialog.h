#ifndef GTKMM_SEEDDIALOG_H
#define GTKMM_SEEDDIALOG_H

#include <gtkmm.h>

class SeedDialog : public Gtk::Dialog {
public:
	SeedDialog();
	SeedDialog(BaseObjectType* w, const Glib::RefPtr<Gtk::Builder>& builder);
	virtual ~SeedDialog();

protected:
  //Signal handlers:
	void on_cancel();
	void on_start();

	Gtk::Button* m_pStart;
	Gtk::Button* m_pCancel;
	Gtk::SpinButton* m_pSeed;
	Glib::RefPtr<Gtk::Builder> m_refGlade;
};

#endif //GTKMM_GAMEWINDOW_H