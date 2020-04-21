#ifndef QTFLOATTOOL_H
#define QTFLOATTOOL_H

#include <QMainWindow>

namespace Ui {
class QtFloatTool;
}

class QtFloatTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtFloatTool(QWidget *parent = nullptr);
    ~QtFloatTool();

    bool get_checkbox_value(int32_t nOffest);
    void set_checkbox_value(int32_t nOffest, bool bValue);
    void set_all_checkbox_value(uint32_t wValue);

    void update_display(uint32_t wBinValue, uint32_t wOption);
    void binary_changed_callback(int32_t nIndex, int32_t nValue);

private slots:
    void on_checkBox_0_stateChanged(int arg1);
    void on_checkBox_1_stateChanged(int arg1);
    void on_checkBox_2_stateChanged(int arg1);
    void on_checkBox_3_stateChanged(int arg1);
    void on_checkBox_4_stateChanged(int arg1);
    void on_checkBox_5_stateChanged(int arg1);
    void on_checkBox_6_stateChanged(int arg1);
    void on_checkBox_7_stateChanged(int arg1);
    void on_checkBox_8_stateChanged(int arg1);
    void on_checkBox_9_stateChanged(int arg1);
    void on_checkBox_10_stateChanged(int arg1);
    void on_checkBox_11_stateChanged(int arg1);
    void on_checkBox_12_stateChanged(int arg1);
    void on_checkBox_13_stateChanged(int arg1);
    void on_checkBox_14_stateChanged(int arg1);
    void on_checkBox_15_stateChanged(int arg1);
    void on_checkBox_16_stateChanged(int arg1);
    void on_checkBox_17_stateChanged(int arg1);
    void on_checkBox_18_stateChanged(int arg1);
    void on_checkBox_19_stateChanged(int arg1);
    void on_checkBox_20_stateChanged(int arg1);
    void on_checkBox_21_stateChanged(int arg1);
    void on_checkBox_22_stateChanged(int arg1);
    void on_checkBox_23_stateChanged(int arg1);
    void on_checkBox_24_stateChanged(int arg1);
    void on_checkBox_25_stateChanged(int arg1);
    void on_checkBox_26_stateChanged(int arg1);
    void on_checkBox_27_stateChanged(int arg1);
    void on_checkBox_28_stateChanged(int arg1);
    void on_checkBox_29_stateChanged(int arg1);
    void on_checkBox_30_stateChanged(int arg1);
    void on_checkBox_31_stateChanged(int arg1);
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();

private:
    Ui::QtFloatTool *ui;
    union {
        struct {
            uint32_t bMantissa   :23;
            uint32_t bExponent   :8;
            uint32_t bSign       :1;
        }tBinBits;
        uint32_t wBinValue = 0;
    };
};

#endif // QTFLOATTOOL_H
