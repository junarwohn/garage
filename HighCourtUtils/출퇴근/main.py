# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'sample.ui'
#
# Created by: PyQt5 UI code generator 5.9.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget, QDialog
import csv
import datetime
from dialog_license import Ui_Dialog as DialogLicense
from doomsLi import Ui_Dialog as InfoLicense
from charmG import Ui_Dialog as charmGong

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1020, 671)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout()
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.listWidget = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget.setObjectName("listWidget")
        self.verticalLayout_5.addWidget(self.listWidget)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.pushButton_6 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_6.setObjectName("pushButton_6")
        self.horizontalLayout_2.addWidget(self.pushButton_6)
        self.pushButton_5 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_5.setObjectName("pushButton_5")
        self.horizontalLayout_2.addWidget(self.pushButton_5)
        self.verticalLayout_5.addLayout(self.horizontalLayout_2)
        self.listWidget_2 = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget_2.setObjectName("listWidget_2")
        self.verticalLayout_5.addWidget(self.listWidget_2)
        self.horizontalLayout.addLayout(self.verticalLayout_5)
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton.sizePolicy().hasHeightForWidth())
        self.pushButton.setSizePolicy(sizePolicy)
        self.pushButton.setObjectName("pushButton")
        self.verticalLayout_4.addWidget(self.pushButton)
        self.pushButton_2 = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_2.sizePolicy().hasHeightForWidth())
        self.pushButton_2.setSizePolicy(sizePolicy)
        self.pushButton_2.setObjectName("pushButton_2")
        self.verticalLayout_4.addWidget(self.pushButton_2)
        self.pushButton_3 = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_3.sizePolicy().hasHeightForWidth())
        self.pushButton_3.setSizePolicy(sizePolicy)
        self.pushButton_3.setObjectName("pushButton_3")
        self.verticalLayout_4.addWidget(self.pushButton_3)
        self.pushButton_4 = QtWidgets.QPushButton(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_4.sizePolicy().hasHeightForWidth())
        self.pushButton_4.setSizePolicy(sizePolicy)
        self.pushButton_4.setObjectName("pushButton_4")
        self.verticalLayout_4.addWidget(self.pushButton_4)
        self.horizontalLayout.addLayout(self.verticalLayout_4)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setSpacing(0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label = QtWidgets.QLabel(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(12)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setMaximumSize(QtCore.QSize(16777215, 25))
        self.label.setObjectName("label")
        self.verticalLayout_3.addWidget(self.label)
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setObjectName("lineEdit")
        self.verticalLayout_3.addWidget(self.lineEdit)
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setMaximumSize(QtCore.QSize(16777215, 25))
        self.label_2.setObjectName("label_2")
        self.verticalLayout_3.addWidget(self.label_2)
        self.lineEdit_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.verticalLayout_3.addWidget(self.lineEdit_2)
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setMaximumSize(QtCore.QSize(16777215, 25))
        self.label_3.setObjectName("label_3")
        self.verticalLayout_3.addWidget(self.label_3)
        self.lineEdit_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.verticalLayout_3.addWidget(self.lineEdit_3)
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy)
        self.label_4.setMinimumSize(QtCore.QSize(0, 25))
        self.label_4.setMaximumSize(QtCore.QSize(16777215, 25))
        self.label_4.setObjectName("label_4")
        self.verticalLayout_3.addWidget(self.label_4)
        self.lineEdit_4 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.verticalLayout_3.addWidget(self.lineEdit_4)
        self.verticalLayout.addLayout(self.verticalLayout_3)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1020, 21))
        self.menubar.setObjectName("menubar")
        self.menuLicense = QtWidgets.QMenu(self.menubar)
        self.menuLicense.setObjectName("menuLicense")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionOpenSourceLicense = QtWidgets.QAction(MainWindow)
        self.actionOpenSourceLicense.setObjectName("actionOpenSourceLicense")
        self.actionDeveloperInfo = QtWidgets.QAction(MainWindow)
        self.actionDeveloperInfo.setObjectName("actionDeveloperInfo")
        self.menuLicense.addAction(self.actionOpenSourceLicense)
        self.menuLicense.addAction(self.actionDeveloperInfo)
        self.menubar.addAction(self.menuLicense.menuAction())


        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)


        self.pushButton.clicked.connect(self.openFileNamesDialog)
        self.pushButton_2.clicked.connect(self.translatePreview)
        self.pushButton_6.clicked.connect(self.upButtonClicked)
        self.pushButton_5.clicked.connect(self.downButtonClicked)
        self.pushButton_3.clicked.connect(self.saveFileDialog)
        self.pushButton_4.clicked.connect(self.infoLicenseView)
        # self.pushButton_4.clicked.connect(self.charmGonigkInit)
        # self.listWidget.setSelectionMode(2)

        self.actionOpenSourceLicense.triggered.connect(self.openSourceLicenseView)
        self.actionDeveloperInfo.triggered.connect(self.infoLicenseView)
        
        
    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("GongikTranslator", "GongikTranslator"))
        self.pushButton_6.setText(_translate("MainWindow", "UP"))
        self.pushButton_5.setText(_translate("MainWindow", "DOWN"))
        self.pushButton.setText(_translate("MainWindow", "FileBrowse"))
        self.pushButton_2.setText(_translate("MainWindow", "TranslatePreview"))
        self.pushButton_3.setText(_translate("MainWindow", "TargetFileBrowse"))
        self.pushButton_4.setText(_translate("MainWindow", "CharmGongik"))
        self.label.setText(_translate("MainWindow", "시작날짜 (YYYY-MM-DD)"))
        self.lineEdit.setText(_translate("MainWindow", "2017-09-01"))
        self.label_2.setText(_translate("MainWindow", "종료날짜 (YYYY-MM-DD)"))
        self.lineEdit_2.setText(_translate("MainWindow", "2017-10-01"))
        self.label_3.setText(_translate("MainWindow", "구분자 (기본 ;)"))
        self.lineEdit_3.setText(_translate("MainWindow", ";"))
        self.label_4.setText(_translate("MainWindow", "파일 안 날짜 표기 순서 (기본 0)"))
        self.lineEdit_4.setText(_translate("MainWindow", "0"))
        self.menuLicense.setTitle(_translate("MainWindow", "License"))
        self.actionOpenSourceLicense.setText(_translate("MainWindow", "OpenSourceLicense"))
        self.actionDeveloperInfo.setText(_translate("MainWindow", "DeveloperInfo"))

    def openFileNamesDialog(self):
        options = QtWidgets.QFileDialog.Options()
        options |= QtWidgets.QFileDialog.DontUseNativeDialog
        files, _ = QtWidgets.QFileDialog.getOpenFileNames(self.pushButton, "FileBrowse", "",
                                                "All Files (*);;CSV Files (*.csv);; Text Files(*.txt);; Python Files (*.py)", options=options)
        if files:
            # print(files)
            self.listWidget.addItems(files)
            for f_name in files:
                # print(f_name)
                f = open(f_name, 'r', encoding='utf-8', newline='')
                rdr = csv.reader(f)
                cnt = 0
                for i in rdr:
                    # print(type(i[0]))
                    # print(i)
                    self.listWidget_2.addItems(i)
                    cnt = cnt + 1
                    if cnt > 3:
                        self.listWidget_2.addItems(["....."])
                        break
                f.close()

    def translatePreview(self):
        self.listWidget_2.clear()
        # for item_index in range(self.listWidget.count()):
            # self.listWidget_2.addItem(self.listWidget.item(item_index).text())
        
        n_th_num = self.lineEdit_4.text()
        identifier = self.lineEdit_3.text()
        # file_names = self.listWidget.selectedItems()
        file_names = []
        for item_index in range(self.listWidget.count()):
            file_names.append(self.listWidget.item(item_index).text())
        print(file_names)
        for file_name in file_names:
            print(file_name)
            n_th_num = int(self.lineEdit_4.text())
            f = open(file_name, 'r', encoding='utf-8', newline='')
            rdr = csv.reader(f)
 
            info_list = []
 
            for info in rdr:
                info_list.append(info[n_th_num])
 
            info_list = info_list[1:]
            time_list = []
            for i in info_list:
                time_list.append(datetime.datetime.strptime((i.split(identifier))[0],'%Y-%m-%d %H:%M:%S' ))
            
            day_start = datetime.datetime.strptime(self.lineEdit.text(), '%Y-%m-%d')
            day_end = datetime.datetime.strptime(self.lineEdit_2.text(), '%Y-%m-%d')
            day_end = day_end + datetime.timedelta(days = 1)
            time = datetime.time(5, 0, 0)
            
            day_start = datetime.datetime.combine(day_start, time)
            day_end = datetime.datetime.combine(day_end, time)
            
            in_times = []
            out_times = []
            while day_start + datetime.timedelta(days=1) <= day_end:
                day_list = [times for times in time_list if (day_start < times and day_start + datetime.timedelta(days = 1) > times)]
                if len(day_list) == 0:
                    in_times.append('')
                    out_times.append('')
                else:
                    in_time = day_list[0].strftime('%H%M')
                    if len(in_time) < 4:
                        in_time = '0' + in_time
                    in_times.append(in_time)
                    out_time = day_list[-1].strftime('%H')
                    if (int(out_time) < 6):
                        out_time = str(int(out_time) + 24)
                    out_times.append(out_time + day_list[-1].strftime('%M'))
                day_start = day_start + datetime.timedelta(days=1)
            self.listWidget_2.addItems(in_times)
            self.listWidget_2.addItems(out_times)
            f.close()
  
  
    # def translateApply(self):
    #     self.listWidget_2.clear()
    #     # for item_index in range(self.listWidget.count()):
    #         # self.listWidget_2.addItem(self.listWidget.item(item_index).text())
        
    #     n_th_num = self.lineEdit_4.text()
    #     identifier = self.lineEdit_3.text()
    #     # file_names = self.listWidget.selectedItems()
    #     file_names = []
    #     for item_index in range(self.listWidget.count()):
    #         file_names.append(self.listWidget.item(item_index).text())
    #     print(file_names)
    #     for file_name in file_names:
    #         print(file_name)
    #         n_th_num = int(self.lineEdit_4.text())
    #         f = open(file_name, 'r', encoding='utf-8', newline='')
    #         rdr = csv.reader(f)
 
    #         info_list = []
 
    #         for info in rdr:
    #             info_list.append(info[n_th_num])
 
    #         info_list = info_list[1:]
    #         time_list = []
    #         for i in info_list:
    #             time_list.append(datetime.datetime.strptime((i.split(identifier))[0],'%Y-%m-%d %H:%M:%S' ))
            
    #         day_start = datetime.datetime.strptime(self.lineEdit.text(), '%Y-%m-%d')
    #         day_end = datetime.datetime.strptime(self.lineEdit_2.text(), '%Y-%m-%d')
    #         day_end = day_end + datetime.timedelta(days = 1)
    #         time = datetime.time(5, 0, 0)
            
    #         day_start = datetime.datetime.combine(day_start, time)
    #         day_end = datetime.datetime.combine(day_end, time)
            
    #         in_times = []
    #         out_times = []
    #         while day_start + datetime.timedelta(days=1) <= day_end:
    #             day_list = [times for times in time_list if (day_start < times and day_start + datetime.timedelta(days = 1) > times)]
    #             if len(day_list) == 0:
    #                 in_times.append('')
    #                 out_times.append('')
    #             else:
    #                 in_time = day_list[0].strftime('%H%M')
    #                 if len(in_time) < 4:
    #                     in_time = '0' + in_time
    #                 in_times.append(in_time)
    #                 out_time = day_list[-1].strftime('%H')
    #                 if (int(out_time) < 24):
    #                     out_time = str(int(out_time) + 24)
    #                 out_times.append(out_time + day_list[-1].strftime('%M'))
    #             day_start = day_start + datetime.timedelta(days=1)
    #         self.listWidget_2.addItems(in_times)
    #         self.listWidget_2.addItems(out_times)
    #         f.close()
            
  
  

        # print(self.listWidget.currentItem().text())
        # file_name = self.listWidget.currentItem().text()
        # f = open(file_name, 'r', encoding='utf-8', newline='')
        # rdr = csv.reader(f)
        # info_list = []
        # for i in rdr :
        #     info_list.append(i[0])
        # info_list = info_list[1:]

        # person_name = info_list[0]
        # person_name = person_name.split('\t')[1]

        # timelist = []
        # for i in info_list:
            # print(i[0])
            # timelist.append(datetime.datetime.strptime((i.split(';'))[0],'%Y-%m-%d %H:%M:%S' ))

    def openSourceLicenseView(self):
        print("asdasd")
        dialog = QDialog()
        dialog.ui = DialogLicense()
        dialog.ui.setupUi(dialog)
        dialog.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        dialog.exec_()
        # DialogLicense.show()
        # w = AppWindow()
        # w.show()
        # timer = QtCore.QTimer()
        # timer.timeout.connect(functions.refreshgui) # I believe this re-imports start.py which calls all of this code again.
        # timer.start(1000)    
        # sys.exit(app_.exec())
    def CharmGongikView(self):
        dialog = QDialog()
        dialog.ui = InfoLicense()
        dialog.ui.setupUi(dialog)
        dialog.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        dialog.exec_()

    # def
    def upButtonClicked(self):
        upDownParam = -1
        currentRow = self.listWidget.currentRow()
        if currentRow + upDownParam == -1:
            return
        currentItem = self.listWidget.takeItem(currentRow)
        self.listWidget.insertItem(currentRow + upDownParam, currentItem)
        self.listWidget.setCurrentRow(currentRow + upDownParam)
   

    def downButtonClicked(self):
        upDownParam = 1
        currentRow = self.listWidget.currentRow()
        if currentRow + upDownParam == self.listWidget.count():
            return
        currentItem = self.listWidget.takeItem(currentRow)
        self.listWidget.insertItem(currentRow + upDownParam, currentItem)
        self.listWidget.setCurrentRow(currentRow + upDownParam)
    
    # ultimate_name = ""
    # def charmGonigkInit(target_file_name):
    #     try :
    #         self.listWidget_2.clear()
    #     # for item_index in range(self.listWidget.count()):
    #         # self.listWidget_2.addItem(self.listWidget.item(item_index).text())
        
    #         n_th_num = self.lineEdit_4.text()
    #         identifier = self.lineEdit_3.text()
    #         # file_names = self.listWidget.selectedItems()
    #         file_names = []
    #         # for item_index in range(self.listWidget.count()):
    #             # file_names.append(self.listWidget.item(item_index).text())
    #         for file_name in file_names:
    #             print(file_name)
    #             n_th_num = int(self.lineEdit_4.text())
    #             f = open(file_name, 'r', encoding='utf-8', newline='')
    #             rdr = csv.reader(f)
    #             info_list = []
    
    #             for info in rdr:
    #                 info_list.append(info[n_th_num])
    
    #             info_list = info_list[1:]
    #             time_list = []
    #             for i in info_list:
    #                 time_list.append(datetime.datetime.strptime((i.split(identifier))[0],'%Y-%m-%d %H:%M:%S' ))
                
    #             day_start = datetime.datetime.strptime(self.lineEdit.text(), '%Y-%m-%d')
    #             day_end = datetime.datetime.strptime(self.lineEdit_2.text(), '%Y-%m-%d')
    #             day_end = day_end + datetime.timedelta(days = 1)
    #             time = datetime.time(5, 0, 0)
    #             day_start = datetime.datetime.combine(day_start, time)
    #             day_end = datetime.datetime.combine(day_end, time)
                
    #             in_times = []
    #             out_times = []
    #             # print("widget is")
    #             # for item_index in range(self.listWidget_2.count()):
    #                 # print(str(self.listWidget_2.item(item_index).text()))
    #             while day_start + datetime.timedelta(days=1) <= day_end:
    #                 day_list = [times for times in time_list if (day_start < times and day_start + datetime.timedelta(days = 1) > times)]
    #                 if len(day_list) == 0:
    #                     in_times.append('')
    #                     out_times.append('')
    #                 else:
    #                     in_time = day_list[0].strftime('%H%M')
    #                     if len(in_time) < 4:
    #                         in_time = '0' + in_time
    #                     in_times.append(in_time)
    #                     out_time = day_list[-1].strftime('%H')
    #                     if (int(out_time) < 24):
    #                         out_time = str(int(out_time) + 24)
    #                     out_times.append(out_time + day_list[-1].strftime('%M'))
    #                 day_start = day_start + datetime.timedelta(days=1)
    #             # print(self.listWidget_2.item.text())
    #             f_save = open(target_file_name, 'a', encoding='utf-8')
    #             wr = csv.writer(f_save)
    #             wr.writerow(in_times)
    #             wr.writerow(out_times)
    #             f_save.close()
    #             # self.listWidget_2.addItems(in_times)
    #             # self.listWidget_2.addItems(out_times)
    #             f.close()
    #     except :
    #         print("rrrrrr")


    def saveFileDialog(self):
        options = QtWidgets.QFileDialog.Options()
        options |= QtWidgets.QFileDialog.DontUseNativeDialog
        fileName, _ = QtWidgets.QFileDialog.getSaveFileName(self.pushButton_3, "QFileDialog.getSaveFileName()", "",
                                                  "CSV Files (*.csv)", options=options)
        if fileName:
            f = open(fileName, 'w', encoding='utf-8')
            wr = csv.writer(f)
            # for item_index in range(self.listWidget_2.count()):
            #     wr.writerow(self.listWidget_2.item(item_index).text())
            # self.listWidget_2.clear()
            # self.listWidget_2.addItem(fileName)
            f.close()
            ultimate_name = fileName
            print(fileName)
        try :
            # self.listWidget_2.clear()
            # for item_index in range(self.listWidget.count()):
                # self.listWidget_2.addItem(self.listWidget.item(item_index).text())
            print(1)
            n_th_num = self.lineEdit_4.text()
            identifier = self.lineEdit_3.text()
            # file_names = self.listWidget.selectedItems()
            file_names = []
            for item_index in range(self.listWidget.count()):
                file_names.append(self.listWidget.item(item_index).text())
            for file_name in file_names:
                print(file_name)
                n_th_num = int(self.lineEdit_4.text())
                f = open(file_name, 'r', encoding='utf-8', newline='')
                rdr = csv.reader(f)
                info_list = []
    
                for info in rdr:
                    info_list.append(info[n_th_num])
    
                info_list = info_list[1:]
                time_list = []
                for i in info_list:
                    time_list.append(datetime.datetime.strptime((i.split(identifier))[0],'%Y-%m-%d %H:%M:%S' ))
                
                day_start = datetime.datetime.strptime(self.lineEdit.text(), '%Y-%m-%d')
                day_end = datetime.datetime.strptime(self.lineEdit_2.text(), '%Y-%m-%d')
                day_end = day_end + datetime.timedelta(days = 1)
                time = datetime.time(5, 0, 0)
                day_start = datetime.datetime.combine(day_start, time)
                day_end = datetime.datetime.combine(day_end, time)
                
                in_times = []
                out_times = []
                # print("widget is")
                # for item_index in range(self.listWidget_2.count()):
                    # print(str(self.listWidget_2.item(item_index).text()))
                while day_start + datetime.timedelta(days=1) <= day_end:
                    day_list = [times for times in time_list if (day_start < times and day_start + datetime.timedelta(days = 1) > times)]
                    if len(day_list) == 0:
                        in_times.append('')
                        out_times.append('')
                    else:
                        in_time = day_list[0].strftime('%H%M')
                        if len(in_time) < 4:
                            in_time = '0' + in_time
                        in_times.append(in_time)
                        out_time = day_list[-1].strftime('%H')
                        if (int(out_time) < 6):
                            out_time = str(int(out_time) + 24)
                        out_times.append(out_time + day_list[-1].strftime('%M'))
                    day_start = day_start + datetime.timedelta(days=1)
                # print(self.listWidget_2.item.text())
                f_save = open(fileName, 'a', encoding='utf-8', newline='')
                wr = csv.writer(f_save)
                print(in_times)
                print(out_times)
                wr.writerow(in_times)
                wr.writerow(out_times)
                f_save.close()
                # self.listWidget_2.addItems(in_times)
                # self.listWidget_2.addItems(out_times)
                f.close()
        except :
            print("rrrrrr")

    def infoLicenseView(self):
        dialog = QDialog()
        dialog.ui = charmGong()
        dialog.ui.setupUi(dialog)
        dialog.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        dialog.exec_()


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())