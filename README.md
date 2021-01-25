# Example Custom Qounter

Example implementation of a Custom Qounter addon for Qounters-.

## Requirements (qpm)
- codegen
- custom-types
- questui
- qounters-minus

## Guide
- Create a custom type extending QountersMinus::Qounter
    - Set up your Qounter elements in a `void Start` method. The parent GameObject will be available as `this->gameObject`
        - Two helpers are available, `CreateBasicTitle(std::string)` and `CreateBasicText(std::string)`. The basicText element is stored in the `this->basicText` instance variable and can be updated later from other methods.
    - If any of the following event handler methods are specified, they will be called automatically at the appropriate moments during gameplay:
        - `OnNoteCut(NoteData* data, NoteCutInfo* info)`
        - `OnNoteMiss(NoteData* data)`
        - `OnScoreUpdated(int modifiedScore)`
        - `OnMaxScoreUpdated(int maxModifiedScore)`
        - `OnSwingRatingFinished(NoteCutInfo* info, ISaberSwingRatingCounter* swingRatingCounter)`
    - References to some commonly-used game components are stored in `this->refs` (see [InjectedComponents](https://github.com/danrouse/bsq-qounters-minus/blob/main/src/InjectedComponents.cpp))
    - All other [UnityEngine.MonoBehaviour](https://docs.unity3d.com/ScriptReference/MonoBehaviour.html) methods can be defined
- For configuration, specify your configurable variables as static fields on your custom type
    - By convention, please include `bool Enabled, int Position, int Distance` following the boilerplate shown here
- In your mod's `load()` entry point:
    - Ensure Qounters- is loaded by calling `Modloader::requireMod("qounters-minus", QOUNTERS_MINUS_VERSION);`
    - Register with custom-types `custom_types::Register::RegisterType<YourCustomQounterType>();`
    - Register your Qounter `QountersMinus::QounterRegistry::Register<YourCustomQounterType>(std::string shortName, std::string fullName, std::string configKey)`
    - Register your configuration with `QountersMinus::QounterRegistry::RegisterConfig<YourCustomQounterType>(configMetadata)` (see [src/ExampleCustomQounter.cpp](src/ExampleCustomQounter.cpp) for example usage or [QounterRegistry.hpp](https://github.com/danrouse/bsq-qounters-minus/blob/main/shared/QounterRegistry.hpp#L31) for all options)

## Credits

* [zoller27osu](https://github.com/zoller27osu), [Sc2ad](https://github.com/Sc2ad) and [jakibaki](https://github.com/jakibaki) - [beatsaber-hook](https://github.com/sc2ad/beatsaber-hook)
* [raftario](https://github.com/raftario)
* [Lauriethefish](https://github.com/Lauriethefish) and [danrouse](https://github.com/danrouse) for [this template](https://github.com/Lauriethefish/quest-mod-template)
