// Mocks generated by Mockito 5.3.2 from annotations
// in polygonid_flutter_sdk/test/domain/use_cases/fetch_and_save_claims_use_case_test.dart.
// Do not manually edit this file.

// ignore_for_file: no_leading_underscores_for_library_prefixes
import 'dart:async' as _i4;

import 'package:mockito/mockito.dart' as _i1;
import 'package:polygonid_flutter_sdk/common/domain/entities/filter_entity.dart'
    as _i7;
import 'package:polygonid_flutter_sdk/credential/domain/entities/claim_entity.dart'
    as _i2;
import 'package:polygonid_flutter_sdk/credential/domain/entities/credential_request_entity.dart'
    as _i6;
import 'package:polygonid_flutter_sdk/credential/domain/repositories/credential_repository.dart'
    as _i5;
import 'package:polygonid_flutter_sdk/iden3comm/domain/use_cases/get_auth_token_use_case.dart'
    as _i3;

// ignore_for_file: type=lint
// ignore_for_file: avoid_redundant_argument_values
// ignore_for_file: avoid_setters_without_getters
// ignore_for_file: comment_references
// ignore_for_file: implementation_imports
// ignore_for_file: invalid_use_of_visible_for_testing_member
// ignore_for_file: prefer_const_constructors
// ignore_for_file: unnecessary_parenthesis
// ignore_for_file: camel_case_types
// ignore_for_file: subtype_of_sealed_class

class _FakeClaimEntity_0 extends _i1.SmartFake implements _i2.ClaimEntity {
  _FakeClaimEntity_0(
    Object parent,
    Invocation parentInvocation,
  ) : super(
          parent,
          parentInvocation,
        );
}

/// A class which mocks [GetAuthTokenUseCase].
///
/// See the documentation for Mockito's code generation for more information.
class MockGetAuthTokenUseCase extends _i1.Mock
    implements _i3.GetAuthTokenUseCase {
  MockGetAuthTokenUseCase() {
    _i1.throwOnMissingStub(this);
  }

  @override
  _i4.Future<String> execute({required _i3.GetAuthTokenParam? param}) =>
      (super.noSuchMethod(
        Invocation.method(
          #execute,
          [],
          {#param: param},
        ),
        returnValue: _i4.Future<String>.value(''),
      ) as _i4.Future<String>);
}

/// A class which mocks [CredentialRepository].
///
/// See the documentation for Mockito's code generation for more information.
class MockCredentialRepository extends _i1.Mock
    implements _i5.CredentialRepository {
  MockCredentialRepository() {
    _i1.throwOnMissingStub(this);
  }

  @override
  _i4.Future<_i2.ClaimEntity> fetchClaim({
    required String? identifier,
    required String? token,
    required _i6.CredentialRequestEntity? credentialRequest,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #fetchClaim,
          [],
          {
            #identifier: identifier,
            #token: token,
            #credentialRequest: credentialRequest,
          },
        ),
        returnValue: _i4.Future<_i2.ClaimEntity>.value(_FakeClaimEntity_0(
          this,
          Invocation.method(
            #fetchClaim,
            [],
            {
              #identifier: identifier,
              #token: token,
              #credentialRequest: credentialRequest,
            },
          ),
        )),
      ) as _i4.Future<_i2.ClaimEntity>);
  @override
  _i4.Future<String> getFetchMessage(
          {required _i6.CredentialRequestEntity? credentialRequest}) =>
      (super.noSuchMethod(
        Invocation.method(
          #getFetchMessage,
          [],
          {#credentialRequest: credentialRequest},
        ),
        returnValue: _i4.Future<String>.value(''),
      ) as _i4.Future<String>);
  @override
  _i4.Future<void> saveClaims({
    required List<_i2.ClaimEntity>? claims,
    required String? identifier,
    required String? privateKey,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #saveClaims,
          [],
          {
            #claims: claims,
            #identifier: identifier,
            #privateKey: privateKey,
          },
        ),
        returnValue: _i4.Future<void>.value(),
        returnValueForMissingStub: _i4.Future<void>.value(),
      ) as _i4.Future<void>);
  @override
  _i4.Future<List<_i2.ClaimEntity>> getClaims({
    List<_i7.FilterEntity>? filters,
    required String? identifier,
    required String? privateKey,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #getClaims,
          [],
          {
            #filters: filters,
            #identifier: identifier,
            #privateKey: privateKey,
          },
        ),
        returnValue:
            _i4.Future<List<_i2.ClaimEntity>>.value(<_i2.ClaimEntity>[]),
      ) as _i4.Future<List<_i2.ClaimEntity>>);
  @override
  _i4.Future<_i2.ClaimEntity> getClaim({
    required String? claimId,
    required String? identifier,
    required String? privateKey,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #getClaim,
          [],
          {
            #claimId: claimId,
            #identifier: identifier,
            #privateKey: privateKey,
          },
        ),
        returnValue: _i4.Future<_i2.ClaimEntity>.value(_FakeClaimEntity_0(
          this,
          Invocation.method(
            #getClaim,
            [],
            {
              #claimId: claimId,
              #identifier: identifier,
              #privateKey: privateKey,
            },
          ),
        )),
      ) as _i4.Future<_i2.ClaimEntity>);
  @override
  _i4.Future<void> removeClaims({
    required List<String>? claimIds,
    required String? identifier,
    required String? privateKey,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #removeClaims,
          [],
          {
            #claimIds: claimIds,
            #identifier: identifier,
            #privateKey: privateKey,
          },
        ),
        returnValue: _i4.Future<void>.value(),
        returnValueForMissingStub: _i4.Future<void>.value(),
      ) as _i4.Future<void>);
  @override
  _i4.Future<_i2.ClaimEntity> updateClaim({
    required _i2.ClaimEntity? claim,
    required String? identifier,
    required String? privateKey,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #updateClaim,
          [],
          {
            #claim: claim,
            #identifier: identifier,
            #privateKey: privateKey,
          },
        ),
        returnValue: _i4.Future<_i2.ClaimEntity>.value(_FakeClaimEntity_0(
          this,
          Invocation.method(
            #updateClaim,
            [],
            {
              #claim: claim,
              #identifier: identifier,
              #privateKey: privateKey,
            },
          ),
        )),
      ) as _i4.Future<_i2.ClaimEntity>);
  @override
  _i4.Future<Map<String, dynamic>?> fetchSchema({required String? url}) =>
      (super.noSuchMethod(
        Invocation.method(
          #fetchSchema,
          [],
          {#url: url},
        ),
        returnValue: _i4.Future<Map<String, dynamic>?>.value(),
      ) as _i4.Future<Map<String, dynamic>?>);
  @override
  _i4.Future<Map<String, dynamic>?> fetchVocab({
    required Map<String, dynamic>? schema,
    required String? type,
  }) =>
      (super.noSuchMethod(
        Invocation.method(
          #fetchVocab,
          [],
          {
            #schema: schema,
            #type: type,
          },
        ),
        returnValue: _i4.Future<Map<String, dynamic>?>.value(),
      ) as _i4.Future<Map<String, dynamic>?>);
  @override
  _i4.Future<Map<String, dynamic>> getRevocationStatus(
          {required _i2.ClaimEntity? claim}) =>
      (super.noSuchMethod(
        Invocation.method(
          #getRevocationStatus,
          [],
          {#claim: claim},
        ),
        returnValue:
            _i4.Future<Map<String, dynamic>>.value(<String, dynamic>{}),
      ) as _i4.Future<Map<String, dynamic>>);
  @override
  _i4.Future<bool> isUsingRHS({required _i2.ClaimEntity? claim}) =>
      (super.noSuchMethod(
        Invocation.method(
          #isUsingRHS,
          [],
          {#claim: claim},
        ),
        returnValue: _i4.Future<bool>.value(false),
      ) as _i4.Future<bool>);
  @override
  _i4.Future<String> getRhsRevocationId({required _i2.ClaimEntity? claim}) =>
      (super.noSuchMethod(
        Invocation.method(
          #getRhsRevocationId,
          [],
          {#claim: claim},
        ),
        returnValue: _i4.Future<String>.value(''),
      ) as _i4.Future<String>);
  @override
  _i4.Future<int> getRevocationNonce({required _i2.ClaimEntity? claim}) =>
      (super.noSuchMethod(
        Invocation.method(
          #getRevocationNonce,
          [],
          {#claim: claim},
        ),
        returnValue: _i4.Future<int>.value(0),
      ) as _i4.Future<int>);
}
