import 'package:injectable/injectable.dart';
import 'package:polygonid_flutter_sdk/domain/common/entities/FIlterEntity.dart';
import 'package:polygonid_flutter_sdk/domain/credential/entities/claim_entity.dart';
import 'package:polygonid_flutter_sdk/domain/credential/entities/credential_request_entity.dart';
import 'package:polygonid_flutter_sdk/domain/credential/use_cases/fetch_and_save_claims_use_case.dart';
import 'package:polygonid_flutter_sdk/domain/credential/use_cases/get_claims_use_case.dart';

@injectable
class CredentialWallet {
  final FetchAndSaveClaimsUseCase _fetchAndSaveClaimsUseCase;
  final GetClaimsUseCase _getClaimsUseCase;

  CredentialWallet(this._fetchAndSaveClaimsUseCase, this._getClaimsUseCase);

  /// Fetch a list of [ClaimEntity] and store them
  Future<List<ClaimEntity>> fetchAndSaveClaims(
      {required List<CredentialRequestEntity> credentialRequests}) {
    return _fetchAndSaveClaimsUseCase.execute(param: credentialRequests);
  }

  /// Get a list of [ClaimEntity] from storage
  /// The list can be filtered by [filters]
  Future<List<ClaimEntity>> getClaims({List<FilterEntity>? filters}) {
    return _getClaimsUseCase.execute(param: filters);
  }

  /// Get a list of [ClaimEntity] from storage from a list of id
  /// This is a shortcut to [getClaims], using a filter on id
  Future<List<ClaimEntity>> getClaimsByIds({required List<String> ids}) {
    return _getClaimsUseCase.execute(param: [
      FilterEntity(operator: FilterOperator.inList, name: 'id', value: ids)
    ]);
  }
}
