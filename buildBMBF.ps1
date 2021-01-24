# Builds a .zip file for loading with BMBF
& $PSScriptRoot/build.ps1

if ($?) {
    Compress-Archive -Path "./libs/arm64-v8a/libexample-custom-qounter.so", "./libs/arm64-v8a/libbeatsaber-hook_1_0_10.so", "./bmbfmod.json" -DestinationPath "./example-custom-qounter_v0.1.0.zip" -Update
}
