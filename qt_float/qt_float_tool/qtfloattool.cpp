#include "qtfloattool.h"
#include "ui_qtfloattool.h"
#include <QDebug>
#include <QValidator>
#include <QRegExp>
#include <float.h>

#define UPDATE_OPTION_CHECKBOX      1
#define UPDATE_OPTION_USER_INPUT    2
#define UPDATE_OPTION_REAL_FLOAT    4
#define UPDATE_OPTION_HEX           8
#define UPDATE_OPTION_BITS          16


QtFloatTool::QtFloatTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtFloatTool)
{
    ui->setupUi(this);

    // 用户输入提示
    ui->lineEdit->setPlaceholderText(tr("请输入浮点值, 范围[-FLT_MAX, FLT_MAX], 键入Enter结束"));

    // 用户输入框限定格式
    QDoubleValidator *validtor = new QDoubleValidator();
    validtor->setRange(-FLT_MAX, FLT_MAX, 22);
    ui->lineEdit->setValidator(validtor);

    // lineEdit设置固定大小
    this->ui->lineEdit->setFixedSize(401, 38);
    this->ui->lineEdit_2->setFixedSize(401, 38);
    this->ui->lineEdit_3->setFixedSize(401, 38);
    this->ui->lineEdit_4->setFixedSize(401, 38);

}

QtFloatTool::~QtFloatTool()
{
    delete ui;
}

void QtFloatTool::binary_changed_callback(int32_t nIndex, int32_t nValue)
{
    uint32_t wValue = this->wBinValue;
    uint32_t wOpts = UPDATE_OPTION_USER_INPUT |
            UPDATE_OPTION_REAL_FLOAT |
            UPDATE_OPTION_HEX |
            UPDATE_OPTION_BITS;

    if (nValue) {
        wValue |= (1 << nIndex);
    } else {
        wValue &= (~(1 << nIndex));
    }

    this->update_display(wValue, wOpts);
}


void QtFloatTool::on_lineEdit_returnPressed()
{
    uint32_t wOpts = UPDATE_OPTION_CHECKBOX |
            UPDATE_OPTION_REAL_FLOAT |
            UPDATE_OPTION_HEX |
            UPDATE_OPTION_BITS | UPDATE_OPTION_USER_INPUT;
    union {
        uint32_t wValue;
        int32_t nValue;
        float fValue;
    } tUnionData;

    tUnionData.fValue = ui->lineEdit->text().toFloat();
    this->update_display(tUnionData.wValue, wOpts);
}

void QtFloatTool::update_display(uint32_t wBinValue, uint32_t wOption)
{
    union {
        uint32_t wValue;
        int32_t nValue;
        float fValue;
    } tUnionData;

    if (wBinValue == this->wBinValue) {
        qDebug() << "no change";
        return;
    }

//    qDebug() << "bin value = " << wBinValue;

    tUnionData.wValue = this->wBinValue = wBinValue;

    if (wOption & UPDATE_OPTION_USER_INPUT) {
        QString val2 = QString("%1").arg(tUnionData.fValue, 0, 'G');
        this->ui->lineEdit->setText(val2);
    }

    if (wOption & UPDATE_OPTION_REAL_FLOAT) {
        QString val = QString("%1").arg(tUnionData.fValue, 0, 'f', 23);
        this->ui->lineEdit_2->setText(val);
    }

    if (wOption & UPDATE_OPTION_HEX) {
        QString key = QString("0x%1").arg(tUnionData.wValue, 8, 16, QLatin1Char('0'));
        this->ui->lineEdit_3->setText(key);
    }

    if (wOption & UPDATE_OPTION_BITS) {
        QString binaryDisplay = "";
        for (int32_t i = 31; i >= 0; --i) {
            if (this->wBinValue & (1 << i)) {
                binaryDisplay += '1';
            } else {
                binaryDisplay += '0';
            }
        }
        this->ui->lineEdit_4->setText(binaryDisplay);
        this->ui->label_13->setText(QString::number(this->tBinBits.bSign));
        this->ui->label_14->setText(QString::number(this->tBinBits.bExponent));
        this->ui->label_15->setText(QString::number(this->tBinBits.bMantissa));
    }

    if (wOption & UPDATE_OPTION_CHECKBOX) {
        this->set_all_checkbox_value(wBinValue);
    }
}

void QtFloatTool::on_pushButton_clicked()
{
    uint32_t wOpts = UPDATE_OPTION_USER_INPUT |
            UPDATE_OPTION_REAL_FLOAT |
            UPDATE_OPTION_HEX |
            UPDATE_OPTION_BITS |
            UPDATE_OPTION_CHECKBOX;

    this->update_display(0, wOpts);
    this->ui->lineEdit->clear();
}

void QtFloatTool::on_checkBox_0_stateChanged(int arg1)
{
    this->binary_changed_callback(0, arg1);
}
void QtFloatTool::on_checkBox_1_stateChanged(int arg1)
{
    this->binary_changed_callback(1, arg1);
}
void QtFloatTool::on_checkBox_2_stateChanged(int arg1)
{
    this->binary_changed_callback(2, arg1);
}
void QtFloatTool::on_checkBox_3_stateChanged(int arg1)
{
    this->binary_changed_callback(3, arg1);
}
void QtFloatTool::on_checkBox_4_stateChanged(int arg1)
{
    this->binary_changed_callback(4, arg1);
}
void QtFloatTool::on_checkBox_5_stateChanged(int arg1)
{
    this->binary_changed_callback(5, arg1);
}
void QtFloatTool::on_checkBox_6_stateChanged(int arg1)
{
    this->binary_changed_callback(6, arg1);
}
void QtFloatTool::on_checkBox_7_stateChanged(int arg1)
{
    this->binary_changed_callback(7, arg1);
}
void QtFloatTool::on_checkBox_8_stateChanged(int arg1)
{
    this->binary_changed_callback(8, arg1);
}
void QtFloatTool::on_checkBox_9_stateChanged(int arg1)
{
    this->binary_changed_callback(9, arg1);
}
void QtFloatTool::on_checkBox_10_stateChanged(int arg1)
{
    this->binary_changed_callback(10, arg1);
}
void QtFloatTool::on_checkBox_11_stateChanged(int arg1)
{
    this->binary_changed_callback(11, arg1);
}
void QtFloatTool::on_checkBox_12_stateChanged(int arg1)
{
    this->binary_changed_callback(12, arg1);
}
void QtFloatTool::on_checkBox_13_stateChanged(int arg1)
{
    this->binary_changed_callback(13, arg1);
}
void QtFloatTool::on_checkBox_14_stateChanged(int arg1)
{
    this->binary_changed_callback(14, arg1);
}
void QtFloatTool::on_checkBox_15_stateChanged(int arg1)
{
    this->binary_changed_callback(15,arg1);
}
void QtFloatTool::on_checkBox_16_stateChanged(int arg1)
{
    this->binary_changed_callback(16, arg1);
}
void QtFloatTool::on_checkBox_17_stateChanged(int arg1)
{
    this->binary_changed_callback(17, arg1);
}
void QtFloatTool::on_checkBox_18_stateChanged(int arg1)
{
    this->binary_changed_callback(18, arg1);
}
void QtFloatTool::on_checkBox_19_stateChanged(int arg1)
{
    this->binary_changed_callback(19, arg1);
}
void QtFloatTool::on_checkBox_20_stateChanged(int arg1)
{
    this->binary_changed_callback(20, arg1);
}
void QtFloatTool::on_checkBox_21_stateChanged(int arg1)
{
    this->binary_changed_callback(21, arg1);
}
void QtFloatTool::on_checkBox_22_stateChanged(int arg1)
{
    this->binary_changed_callback(22, arg1);
}
void QtFloatTool::on_checkBox_23_stateChanged(int arg1)
{
    this->binary_changed_callback(23, arg1);
}void QtFloatTool::on_checkBox_24_stateChanged(int arg1)
{
    this->binary_changed_callback(24, arg1);
}
void QtFloatTool::on_checkBox_25_stateChanged(int arg1)
{
    this->binary_changed_callback(25, arg1);
}
void QtFloatTool::on_checkBox_26_stateChanged(int arg1)
{
    this->binary_changed_callback(26, arg1);
}
void QtFloatTool::on_checkBox_27_stateChanged(int arg1)
{
    this->binary_changed_callback(27, arg1);
}
void QtFloatTool::on_checkBox_28_stateChanged(int arg1)
{
    this->binary_changed_callback(28, arg1);
}
void QtFloatTool::on_checkBox_29_stateChanged(int arg1)
{
    this->binary_changed_callback(29, arg1);
}
void QtFloatTool::on_checkBox_30_stateChanged(int arg1)
{
    this->binary_changed_callback(30, arg1);
}
void QtFloatTool::on_checkBox_31_stateChanged(int arg1)
{
    this->binary_changed_callback(31, arg1);
}

bool QtFloatTool::get_checkbox_value(int32_t nOffest)
{
    switch (nOffest) {
    case 0:
        return ui->checkBox_0->isChecked();
    case 1:
        return ui->checkBox_1->isChecked();
    case 2:
        return ui->checkBox_2->isChecked();
    case 3:
        return ui->checkBox_3->isChecked();
    case 4:
        return ui->checkBox_4->isChecked();
    case 5:
        return ui->checkBox_5->isChecked();
    case 6:
        return ui->checkBox_6->isChecked();
    case 7:
        return ui->checkBox_7->isChecked();
    case 8:
        return ui->checkBox_8->isChecked();
    case 9:
        return ui->checkBox_9->isChecked();
    case 10:
        return ui->checkBox_10->isChecked();
    case 11:
        return ui->checkBox_11->isChecked();
    case 12:
        return ui->checkBox_12->isChecked();
    case 13:
        return ui->checkBox_13->isChecked();
    case 14:
        return ui->checkBox_14->isChecked();
    case 15:
        return ui->checkBox_15->isChecked();
    case 16:
        return ui->checkBox_16->isChecked();
    case 17:
        return ui->checkBox_17->isChecked();
    case 18:
        return ui->checkBox_18->isChecked();
    case 19:
        return ui->checkBox_19->isChecked();
    case 20:
        return ui->checkBox_20->isChecked();
    case 21:
        return ui->checkBox_21->isChecked();
    case 22:
        return ui->checkBox_22->isChecked();
    case 23:
        return ui->checkBox_23->isChecked();
    case 24:
        return ui->checkBox_24->isChecked();
    case 25:
        return ui->checkBox_25->isChecked();
    case 26:
        return ui->checkBox_26->isChecked();
    case 27:
        return ui->checkBox_27->isChecked();
    case 28:
        return ui->checkBox_28->isChecked();
    case 29:
        return ui->checkBox_29->isChecked();
    case 30:
        return ui->checkBox_30->isChecked();
    case 31:
        return ui->checkBox_31->isChecked();
    }
    return false;
}

void QtFloatTool::set_checkbox_value(int32_t nOffest, bool bValue)
{
    switch (nOffest) {
    case 0:
        ui->checkBox_0->setChecked(bValue);break;
    case 1:
        ui->checkBox_1->setChecked(bValue);break;
    case 2:
        ui->checkBox_2->setChecked(bValue);break;
    case 3:
        ui->checkBox_3->setChecked(bValue);break;
    case 4:
        ui->checkBox_4->setChecked(bValue);break;
    case 5:
        ui->checkBox_5->setChecked(bValue);break;
    case 6:
        ui->checkBox_6->setChecked(bValue);break;
    case 7:
        ui->checkBox_7->setChecked(bValue);break;
    case 8:
        ui->checkBox_8->setChecked(bValue);break;
    case 9:
        ui->checkBox_9->setChecked(bValue);break;
    case 10:
        ui->checkBox_10->setChecked(bValue);break;
    case 11:
        ui->checkBox_11->setChecked(bValue);break;
    case 12:
        ui->checkBox_12->setChecked(bValue);break;
    case 13:
        ui->checkBox_13->setChecked(bValue);break;
    case 14:
        ui->checkBox_14->setChecked(bValue);break;
    case 15:
        ui->checkBox_15->setChecked(bValue);break;
    case 16:
        ui->checkBox_16->setChecked(bValue);break;
    case 17:
        ui->checkBox_17->setChecked(bValue);break;
    case 18:
        ui->checkBox_18->setChecked(bValue);break;
    case 19:
        ui->checkBox_19->setChecked(bValue);break;
    case 20:
        ui->checkBox_20->setChecked(bValue);break;
    case 21:
        ui->checkBox_21->setChecked(bValue);break;
    case 22:
        ui->checkBox_22->setChecked(bValue);break;
    case 23:
        ui->checkBox_23->setChecked(bValue);break;
    case 24:
        ui->checkBox_24->setChecked(bValue);break;
    case 25:
        ui->checkBox_25->setChecked(bValue);break;
    case 26:
        ui->checkBox_26->setChecked(bValue);break;
    case 27:
        ui->checkBox_27->setChecked(bValue);break;
    case 28:
        ui->checkBox_28->setChecked(bValue);break;
    case 29:
        ui->checkBox_29->setChecked(bValue);break;
    case 30:
        ui->checkBox_30->setChecked(bValue);break;
    case 31:
        ui->checkBox_31->setChecked(bValue);break;
    }
}

void QtFloatTool::set_all_checkbox_value(uint32_t nValue)
{
    for (int32_t i = 0; i < 32; ++i) {
        this->set_checkbox_value(i, nValue & (1 << i));
    }
}
