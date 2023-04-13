<p align="center">
  <img src="example/assets/images/polygon_id_logo.svg" width="120" height="120">
</p>
 
# Polygon ID Flutter SDK

[![pub package](https://img.shields.io/badge/pub-2.1.1-blueviolet)](https://pub.dev/packages/polygonid_flutter_sdk)
[![build](https://github.com/iden3/polygonid-flutter-sdk/workflows/polygonid_flutter_sdk/badge.svg)](https://github.com/iden3/polygonid-flutter-sdk/actions?query=workflow%3Apolygonid_flutter_sdk)
[![codecov](https://codecov.io/gh/iden3/polygonid-flutter-sdk/branch/develop/graph/badge.svg?token=0SI0XWGXKL)](https://codecov.io/gh/iden3/polygonid-flutter-sdk)
[![license](https://img.shields.io/badge/License-agpl-blue.svg)](https://github.com/iden3/polygonid-flutter-sdk/blob/master/LICENSE)

## Description

This is a Flutter plugin for the [Polygon ID SDK](https://polygon.technology/polygon-id), which allows you to integrate Polygon ID identity system into your Flutter apps.

## Installation

To use this plugin, add `polygonid_flutter_sdk` as a [dependency](https://flutter.io/using-packages/) in your `pubspec.yaml` file like this

```yaml
dependencies:
  polygonid_flutter_sdk: ^x.y.z
```
This will get you the latest version.

If you want to test a specific branch of the repository, pull `polygonid_flutter_sdk` like this

```yaml
dependencies:
  polygonid_flutter_sdk:
      git:
        url: ssh://git@github.com/iden3/polygonid-flutter-sdk.git
        ref: branchPathName
```

# Environment
### App side
You need to set the environment you are working on in the SDK.

You can either set the environment during initialization (with `env` parameter) or later with [PolygonIdSdk.setEnv()](lib/sdk/polygon_id_sdk.dart#L62).

The environment object is [EnvEntity](lib/common/domain/entities/env_entity.dart) with:
```
  final String blockchain; # The name of the blockchain (eg: polygon)
  final String network; # The network of the blockchain (eg: mumbai)
  final String web3Url; # URL of the blockchain (eg: https://polygon-mumbai.infura.io/v3/)
  final String web3RdpUrl; # RDP URL (eg: wss://polygon-mumbai.infura.io/v3/)
  final String web3ApiKey; # The API key of the web3 URL service (eg: a536514602ea4e22a2e9007b6e9dbc63)
  final String idStateContract; # The ID state contract (eg: 0x134B1BE34911E39A8397ec6289782989729807a4)
  final String pushUrl; # The push notification URL (eg: https://push-staging.polygonid.com/api/v1)
```

An example of initialization:
```dart
import 'package:flutter/material.dart';
import 'package:polygonid_flutter_sdk/sdk/polygon_id_sdk.dart';

Future<void> main() async {
  await PolygonIdSdk.init(env: EnvEntity(
      blockchain: 'polygon',
      network: 'mumbai',
      web3Url: 'https://polygon-mumbai.infura.io/v3/'
      web3RdpUrl: 'wss://polygon-mumbai.infura.io/v3/'
      web3ApiKey: 'YOUR-INFURA-API-KEY'
      idStateContract: '0x134B1BE34911E39A8397ec6289782989729807a4'
      pushUrl: 'https://push-staging.polygonid.com/api/v1',
  ));
  runApp(const App());
}
```

### Supported Environments

| Environment   |      Polygon Mumbai                           |  Polygon Main |
|------------------|:------------------------------------------:|:-------------:|
| blockchain       |         polygon                            |  coming soon  |
| network          |         mumbai                             |  coming soon  |
| web3Url          | https://polygon-mumbai.infura.io/v3/       |  coming soon  |
| web3RdpUrl       | wss://polygon-mumbai.infura.io/v3/         |  coming soon  |
| idStateContract  | 0x134B1BE34911E39A8397ec6289782989729807a4 |  coming soon  |
| pushUrl          | https://push-staging.polygonid.com/api/v1  |  coming soon  |

If you want to deploy your own State Contract, please check the [contract documentation](https://docs.iden3.io/contracts/state/).

You can get the current env using [PolygonIdSdk.getEnv()](lib/sdk/polygon_id_sdk.dart#L66).

# Deploy and check
### Deploy
1. Clone this repository.
2. Run `build_runner` to generate `.g.dart` files:
```bash
flutter pub run build_runner build --delete-conflicting-outputs
```

For iOS only:

1. Add to your app's Podfile the following post_install code:

```
post_install do |installer|  
  installer.pods_project.targets.each do |target|
    ...
    end
    # polygonid-setup
      target.build_configurations.each do |config|
        cflags = config.build_settings['OTHER_CFLAGS'] || ['$(inherited)']
        cflags << '-fembed-bitcode'
        config.build_settings['OTHER_CFLAGS'] = cflags
        config.build_settings['SWIFT_VERSION'] = '5.0'
        config.build_settings['ENABLE_BITCODE'] = 'NO'
        config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '14.0'
        config.build_settings['STRIP_STYLE'] = 'non-global'
      end
    if target.name == "Pods-Runner"
      puts "Updating #{target.name} OTHER_LDFLAGS"
      target.build_configurations.each do |config|
                      xcconfig_path = config.base_configuration_reference.real_path
                      xcconfig = File.read(xcconfig_path)
                      new_xcconfig = xcconfig.sub('OTHER_LDFLAGS = $(inherited)', 'OTHER_LDFLAGS = $(inherited) -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/librapidsnark.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libwitnesscalc_authV2.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libwitnesscalc_credentialAtomicQueryMTPV2.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libwitnesscalc_credentialAtomicQuerySigV2.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libwitnesscalc_credentialAtomicQueryMTPV2OnChain.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libwitnesscalc_credentialAtomicQuerySigV2OnChain.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libfr.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libgmp.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libpolygonid.a" -force_load "${PODS_ROOT}/../.symlinks/plugins/polygonid_flutter_sdk/ios/libbabyjubjub.a"')
                      File.open(xcconfig_path, "w") { |file| file << new_xcconfig }
         end
     end
  end
end
```
## Usage

To integrate Polygon ID Flutter SDK into your Flutter app, follow these steps:

1. Import the `polygonid_flutter_sdk` package:

```dart
import 'package:polygonid_flutter_sdk/sdk/polygon_id_sdk.dart';
```
2. Initialize the Polygon ID Flutter SDK with your environment:

```dart
await PolygonIdSdk.init(env: EnvEntity(
      blockchain: 'polygon',
      network: 'mumbai',
      web3Url: 'https://polygon-mumbai.infura.io/v3/'
      web3RdpUrl: 'wss://polygon-mumbai.infura.io/v3/'
      web3ApiKey: 'YOUR-INFURA-API-KEY'
      idStateContract: '0x134B1BE34911E39A8397ec6289782989729807a4'
      pushUrl: 'https://push-staging.polygonid.com/api/v1',
  ));
```
3. To be able to authenticate with issuers or verifiers, fetch credentials and generate proofs, you need to download the proof circuit files.

```dart
Stream<DownloadInfo> stream =
        await PolygonIdSdk.I.proof.initCircuitsDownloadAndGetInfoStream;
```
For more information on how to use the PolygonID Flutter SDK, please check the [example app](https://github.com/iden3/polygonid-flutter-sdk/tree/develop/example) included in the repository and follow the [Polygon ID Wallet SDK Documentation](https://0xpolygonid.github.io/tutorials/wallet/wallet-sdk/polygonid-sdk/polygonid-sdk-overview/)

## Issues and Contributions

If you encounter any issues with this SDK, please file an [issue][tracker]. Contributions are also welcome - simply fork this repository, make your changes, and submit a pull request.

[tracker]: https://github.com/iden3/polygonid-flutter-sdk/issues

## Resources

- [Polygon ID website](https://polygon.technology/polygon-id/)
- [Polygon ID GitHub repository](https://github.com/0xPolygonId/)
- [Polygon ID Documentation](https://0xpolygonid.github.io/tutorials/)
- [Flutter documentation](https://flutter.dev/docs)

## Notes

P.S. Using iOS simulator for testing wallet sdk is right now under maintenance and will be available soon.
