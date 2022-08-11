import 'package:polygonid_flutter_sdk/common/mappers/to_mapper.dart';
import 'package:polygonid_flutter_sdk/domain/common/entities/FIlterEntity.dart';
import 'package:sembast/sembast.dart';

import 'filter_mapper.dart';

class FiltersMapper extends ToMapper<Filter, List<FilterEntity>> {
  final FilterMapper _filterMapper;

  FiltersMapper(this._filterMapper);

  @override
  Filter mapTo(List<FilterEntity> to) {
    return Filter.and(to.map((filter) => _filterMapper.mapTo(filter)).toList());
  }
}
