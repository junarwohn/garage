# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Main.ui'
#
# Created by: PyQt5 UI code generator 5.9.1
#
# WARNING! All changes made in this file will be lost!
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets
import re
from DailySituationReport import DailySituationReport as DSR
import openpyxl

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(711, 767)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.tableWidget = QtWidgets.QTableWidget(self.centralwidget)
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(5)
        self.tableWidget.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget.setHorizontalHeaderItem(4, item)
        self.verticalLayout.addWidget(self.tableWidget)
        self.tableWidget_2 = QtWidgets.QTableWidget(self.centralwidget)
        self.tableWidget_2.setObjectName("tableWidget_2")
        self.tableWidget_2.setColumnCount(5)
        self.tableWidget_2.setRowCount(0)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_2.setHorizontalHeaderItem(4, item)
        self.verticalLayout.addWidget(self.tableWidget_2)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setSpacing(3)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(30)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton.sizePolicy().hasHeightForWidth())
        self.pushButton.setSizePolicy(sizePolicy)
        self.pushButton.setMinimumSize(QtCore.QSize(30, 0))
        self.pushButton.setObjectName("pushButton")
        self.verticalLayout_2.addWidget(self.pushButton)
        self.pushButton_2 = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_2.sizePolicy().hasHeightForWidth())
        self.pushButton_2.setSizePolicy(sizePolicy)
        self.pushButton_2.setObjectName("pushButton_2")
        self.verticalLayout_2.addWidget(self.pushButton_2)
        self.pushButton_3 = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_3.sizePolicy().hasHeightForWidth())
        self.pushButton_3.setSizePolicy(sizePolicy)
        self.pushButton_3.setObjectName("pushButton_3")
        self.verticalLayout_2.addWidget(self.pushButton_3)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.horizontalLayout_2.addLayout(self.horizontalLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 711, 21))
        self.menubar.setObjectName("menubar")
        self.menuLicense = QtWidgets.QMenu(self.menubar)
        self.menuLicense.setObjectName("menuLicense")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionPyQt_License = QtWidgets.QAction(MainWindow)
        self.actionPyQt_License.setObjectName("actionPyQt_License")
        self.actionInfo = QtWidgets.QAction(MainWindow)
        self.actionInfo.setObjectName("actionInfo")
        self.menuLicense.addAction(self.actionPyQt_License)
        self.menuLicense.addAction(self.actionInfo)
        self.menubar.addAction(self.menuLicense.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.tableWidget.resize(200,200)
        self.tableWidget_2.resize(200,200)
        self.pushButton.clicked.connect(self.openFileNamesDialog)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("MainWindow", "Mon"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("MainWindow", "Tue"))
        item = self.tableWidget.horizontalHeaderItem(2)
        item.setText(_translate("MainWindow", "Wed"))
        item = self.tableWidget.horizontalHeaderItem(3)
        item.setText(_translate("MainWindow", "Thu"))
        item = self.tableWidget.horizontalHeaderItem(4)
        item.setText(_translate("MainWindow", "Fri"))
        item = self.tableWidget_2.horizontalHeaderItem(0)
        item.setText(_translate("MainWindow", "Mon"))
        item = self.tableWidget_2.horizontalHeaderItem(1)
        item.setText(_translate("MainWindow", "Tue"))
        item = self.tableWidget_2.horizontalHeaderItem(2)
        item.setText(_translate("MainWindow", "Wed"))
        item = self.tableWidget_2.horizontalHeaderItem(3)
        item.setText(_translate("MainWindow", "Thu"))
        item = self.tableWidget_2.horizontalHeaderItem(4)
        item.setText(_translate("MainWindow", "Fri"))
        self.pushButton.setText(_translate("MainWindow", "FileBrowse"))
        self.pushButton_2.setText(_translate("MainWindow", "TargetFileBrowse"))
        self.pushButton_3.setText(_translate("MainWindow", "CharmGongik"))
        self.menuLicense.setTitle(_translate("MainWindow", "License"))
        self.actionPyQt_License.setText(_translate("MainWindow", "PyQt License"))
        self.actionInfo.setText(_translate("MainWindow", "Info"))

    def openFileNamesDialog(self):
        options = QtWidgets.QFileDialog.Options()
        options |= QtWidgets.QFileDialog.DontUseNativeDialog
        files_, _ = QtWidgets.QFileDialog.getOpenFileNames(self.pushButton, "FileBrowse", "",
                                                "Excel Files (*.xlsx);;", options=options)
        self.tableWidget.setRowCount(100)
        self.tableWidget.setColumnCount(5)
        row_index = 0
        for file_ in files_:
            print(file_)
            wb = openpyxl.load_workbook(file_)

            w = wb.active

            week_infos = [[], [], [], [], []]
            dsr_results = [[], [], [], [], []]

            for i in w.rows:
                for n in range(5):
                    if (i[n].value != None):
                        week_infos[n].append(i[n].value)

            # print(day_infos)
            
            for x in range(len(week_infos)):
                for y in range(len(week_infos[x])):
                    # print(week_infos[x][y])
                    self.tableWidget.setItem(y + row_index, x, QTableWidgetItem(week_infos[x][y]))
            for x in range(len(week_infos)):
                if row_index < len(week_infos[x]):
                    row_index = len(week_infos[x])

            print(row_index) 
            for day_infos_index in range(len(week_infos)):
                for info in week_infos[day_infos_index]:
                    # print(info)
                    # print(info)
                    # print("************************")
                    dsr_ = DSR(day_infos_index, str(info))
                    dsr_results[day_infos_index].append(dsr_)


            self.tableWidget_2.setRowCount(100)
            self.tableWidget_2.setColumnCount(5)
            for x in range(len(dsr_results)):
                print("===============" + str(x) + "day=====================")
                for y in range(len(dsr_results[x])):
                    print(dsr_results[x][y].print())
                    # print()
                    self.tableWidget_2.setItem(y + row_index, x, QTableWidgetItem(dsr_results[x][y].print()))
        self.tableWidget.resizeColumnsToContents()
        self.tableWidget.resizeRowsToContents()
        self.tableWidget_2.resizeColumnsToContents()
        self.tableWidget_2.resizeRowsToContents()


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())