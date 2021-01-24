#include "ExampleCustomQounter.hpp"

DEFINE_CLASS(ExampleCustomQounter::Qounter);

bool ExampleCustomQounter::Qounter::Enabled = true;
int ExampleCustomQounter::Qounter::Position = static_cast<int>(QountersMinus::QounterPosition::BelowMultiplier);
int ExampleCustomQounter::Qounter::Distance = 1;

void ExampleCustomQounter::Qounter::Register() {
    QountersMinus::QounterRegistry::Register<ExampleCustomQounter::Qounter>("Example", "Example Custom Qounter", "ExampleCustomConfig");
    QountersMinus::QounterRegistry::RegisterConfig<ExampleCustomQounter::Qounter>({
        .ptr = &Enabled,
        .field = "Enabled",
    });
    QountersMinus::QounterRegistry::RegisterConfig<ExampleCustomQounter::Qounter>({
        .ptr = &Position,
        .field = "Position",
        .enumNumElements = QountersMinus::QounterPositionCount,
        .enumDisplayNames = QountersMinus::QounterPositionNames,
        .enumSerializedNames = QountersMinus::QounterPositionLookup,
    });
    QountersMinus::QounterRegistry::RegisterConfig<ExampleCustomQounter::Qounter>({
        .ptr = &Distance,
        .field = "Distance",
    });
}

void ExampleCustomQounter::Qounter::Start() {
    srand((unsigned int)time(0));
    CreateBasicTitle("Example");
    CreateBasicText("0");
}

void ExampleCustomQounter::Qounter::OnNoteCut(Il2CppObject* data, Il2CppObject* info) {
    basicText->set_color({float(rand())/float(RAND_MAX), float(rand())/float(RAND_MAX), float(rand())/float(RAND_MAX), 1.0f});
}
