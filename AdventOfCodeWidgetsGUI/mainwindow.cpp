#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include "../2025/solutions.hh"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
		ui(new Ui::MainWindow)
{
	this->setFixedHeight(350);
	ui->setupUi(this);

	m_grid = new QGridLayout(ui->centralwidget);
	m_titles = {
		new QLabel("Puzzle"),
		new QLabel("Part 1"),
		new QLabel("Part 2"),
		new QLabel("Time"),
		new QLabel("Avg. Time"),
	};

	for (int i = 0; i < m_titles.size(); i++)
	{
		m_grid->addWidget(m_titles.at(i), 0, i);
	}

	for (int i = 1; i <= 12; i++)
	{
		m_labels1.push_back(new QLabel(QString::number(i)));
		m_grid->addWidget(m_labels1.back(), i, 0);
		m_labels2.push_back(new QLabel(""));
		m_grid->addWidget(m_labels2.back(), i, 1);
		m_labels3.push_back(new QLabel(""));
		m_grid->addWidget(m_labels3.back(), i, 2);
		m_labels4.push_back(new QLabel(""));
		m_grid->addWidget(m_labels4.back(), i, 3);
	}

	auto runButton = new QPushButton("Run puzzles");
	m_grid->addWidget(runButton, 13, 2);

	connect(runButton, &QPushButton::clicked, this, &MainWindow::runSolutions);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::runSolutions()
{
	std::vector<std::pair<std::string, std::string>(*)()> solutions =
	 {
		 [](){return day1 ::solve(std::ifstream("../2025/inputs/input1.txt"));},
		 [](){return day2 ::solve(std::ifstream("../2025/inputs/input2.txt"));},
		 [](){return day3 ::solve(std::ifstream("../2025/inputs/input3.txt"));},
		 [](){return day4 ::solve(std::ifstream("../2025/inputs/input4.txt"));},
		 [](){return day5 ::solve(std::ifstream("../2025/inputs/input5.txt"));},
		 [](){return day6 ::solve(std::ifstream("../2025/inputs/input6.txt"));},
		 [](){return day7 ::solve(std::ifstream("../2025/inputs/input7.txt"));},
		 [](){return day8 ::solve(std::ifstream("../2025/inputs/input8.txt"));},
		 [](){return day9 ::solve(std::ifstream("../2025/inputs/input9.txt"));},
		 [](){return day10::solve(std::ifstream("../2025/inputs/input10.txt"));},
		 [](){return day11::solve(std::ifstream("../2025/inputs/input11.txt"));},
		 [](){return day12::solve(std::ifstream("../2025/inputs/input12.txt"));},
	 };

	unsigned int i = 0;
	for (auto func : solutions)
	{
		auto start = std::chrono::high_resolution_clock::now();
		auto values = func();
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		m_labels2.at(i)->setText(QString::fromStdString(values.first));
		m_labels3.at(i)->setText(QString::fromStdString(values.second));
		m_labels4.at(i)->setText(QString::number(duration.count()));
		i++;
		this->show();
	}
}
