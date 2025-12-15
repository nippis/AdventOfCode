#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;

	QGridLayout* m_grid;

	QPushButton* m_button1;
	std::vector<QLabel*> m_labels1;
	std::vector<QLabel*> m_labels2;
	std::vector<QLabel*> m_labels3;
	std::vector<QLabel*> m_labels4;
	std::vector<QLabel*> m_titles;

private slots:
	void runSolutions();
};
#endif // MAINWINDOW_H
