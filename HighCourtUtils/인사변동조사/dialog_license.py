# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'dialog_license.ui'
#
# Created by: PyQt5 UI code generator 5.9.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(400, 300)
        self.horizontalLayout = QtWidgets.QHBoxLayout(Dialog)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.plainTextEdit = QtWidgets.QPlainTextEdit(Dialog)
        self.plainTextEdit.setObjectName("plainTextEdit")
        self.horizontalLayout.addWidget(self.plainTextEdit)

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)
        self.plainTextEdit.setDisabled(True)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.plainTextEdit.setPlainText(_translate("Dialog", "PyQt5 is dual licensed on all platforms under the Riverbank Commercial License and the GPL v3. Your PyQt5 license must be compatible with your Qt license. If you use the GPL version then your own code must also use a compatible license.\n"
"\n"
"PyQt5, unlike Qt, is not available under the LGPL\n"
""))

