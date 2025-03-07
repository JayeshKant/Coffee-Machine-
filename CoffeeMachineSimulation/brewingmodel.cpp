#include "BrewingModel.h"
#include "BrewingEngine.h"
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>

//! Constructor initializes BrewingEngine and brewing steps.
BrewingModel::BrewingModel(QObject *parent)
    : QObject(parent), m_engine(new BrewingEngine(this)), m_stepIndex(0)
{
    // Define brewing sequence
    m_steps = {
        { &BrewingEngine::grindBeans,  "🔄 Grinding Coffee Beans..." },
        { &BrewingEngine::heatWater,   "🔥 Heating Water..." },
        { &BrewingEngine::heatMilk,   "🔥 Heating Milk..." },
        { &BrewingEngine::preInfuse,   "💦 Pre-infusing Coffee Grounds..." },
        { &BrewingEngine::extract,     "☕ Extracting Coffee..." },
        { &BrewingEngine::dispense,    "🍶 Dispensing Coffee..." }


    };
}

BrewingModel::~BrewingModel()
{
    delete m_engine;
}


//! Starts the brewing process with delays between each step.
void BrewingModel::startBrewing()
{
    qDebug() << "Starting brewing process...";
    m_stepIndex = 0; // Reset to first step
    nextStep();      // Start brewing steps
}

//! Executes the next brewing step and schedules the next one.
void BrewingModel::nextStep()
{
    if (m_stepIndex >= m_steps.size()) {
        emit brewingStepChanged("✅ Brewing completed!");
        emit brewingFinished();
        return;
    }

    // Get current step
    auto &step = m_steps[m_stepIndex];

    // Log to console
    qDebug() << "⚙️ Brewing step:" << m_stepIndex + 1 << "/" << m_steps.size() << " - " << step.description;

    // Emit step changed for UI update
    emit brewingStepChanged(step.description);

    // Ensure UI updates before executing the brewing function
    QCoreApplication::processEvents();

    // Execute the brewing function with a small delay to allow UI refresh
    QTimer::singleShot(500, [this, step]() {
        (m_engine->*(step.func))();  // Run brewing function (e.g. grindBeans, heatWater, etc.)
    });

    // Move to the next step after a longer delay
    m_stepIndex++;
    if (m_stepIndex < m_steps.size()) {
        QTimer::singleShot(2500, this, &BrewingModel::nextStep); // Delay next step by 2.5 sec
    } else {
        // Final delay for brewing completion
        QTimer::singleShot(2500, [this]() {
            //qDebug() << "✅ Brewing process completed!";
            emit brewingStepChanged("✅ Brewing completed!");
            emit brewingFinished();
        });
    }
}



//! Stops brewing and triggers cleanup.
void BrewingModel::stopBrewing()
{
    qDebug() << "Stopping brewing process...";
    m_engine->cleanUp();
    m_stepIndex = m_steps.size();  // Prevent further steps
}

//! Handles brewing state changes (future use).
void BrewingModel::handleBrewStateChange()
{
    qDebug() << "Handling brewing state change...";
}
