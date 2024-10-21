#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

struct TestConfig;
struct TestNotification;
struct Device;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ExercisesModel;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
    void startTestPressed();

private:
  std::unique_ptr<Ui::MainWindow> ui;
  ExercisesModel* model;
  std::unique_ptr<QThread> workerThread;
  Device* device;

  static void test_callback(const TestNotification* notification,
                            void* cb_data);
  void startTest(const QStringList& exercises);

signals:
  void triggerTest(TestConfig* testConfig);
  void exerciseChanged(uint ex);
  void ffUpdated(uint ex, double ff);
  void receivedRawSample(double sample);
};
#endif // MAINWINDOW_H
