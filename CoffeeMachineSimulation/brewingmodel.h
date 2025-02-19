#pragma once

#include <QObject>

class BrewingEngine;
class QTimer;

class BrewingModel : public QObject
{
    Q_OBJECT
public:
    explicit BrewingModel(QObject *parent = nullptr);
    ~BrewingModel();

    void startBrewing();
    void stopBrewing();
    void handleBrewStateChange();

signals:
    void brewingStepChanged(const QString &step);
    void brewingFinished();

private slots:
    void nextStep();

private:
    BrewingEngine *m_engine;

    // We'll keep track of which step we're on
    int m_stepIndex;
    // A small struct or use a simple function pointer approach
    // For example, each step is: method pointer + description
    struct BrewStep {
        void (BrewingEngine::*func)();  // pointer to a BrewingEngine method
        QString description;            // text to emit
    };
    // The list of steps
    QList<BrewStep> m_steps;
};
