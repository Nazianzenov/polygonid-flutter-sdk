/* Code generated by cmd/cgo; DO NOT EDIT. */

/* package github.com/iden3/go_iden3_core_clib/cmd/libiden3core */


#line 1 "cgo-builtin-export-prolog"

#include <stddef.h> /* for ptrdiff_t below */

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef struct { const char *p; ptrdiff_t n; } _GoString_;
#endif

#endif

/* Start of preamble from import "C" comments.  */


#line 3 "main.go"

#include <stddef.h>
#include <string.h>
#include <stdlib.h> // for C.free
#include <stdbool.h> // for bool
#include <time.h> // for time_t

#define IDEN_MT_HASH_SIZE 32
#define IDEN_ENTRY_DIM 4
#define IDEN_ID_SIZE 31
#define IDEN_BJJ_SIGNATURE_SIZE 64

typedef struct _IDENBigInt {
	unsigned char* data;
	size_t data_len;
} IDENBigInt;

typedef enum
{
	IDENTREEENTRY_OK,
	IDENTREEENTRY_OUT_OF_MEMORY,
	IDENTREEENTRY_CREATE_CLAIM_ERROR,
	IDENTREEENTRY_EXTRACT_CLAIM_ERROR,
} IDENtreeEntryStatus;

typedef struct _IDENMerkleTreeEntry
{
	unsigned char index[IDEN_ENTRY_DIM][IDEN_MT_HASH_SIZE];
	unsigned char value[IDEN_ENTRY_DIM][IDEN_MT_HASH_SIZE];
} IDENMerkleTreeEntry;

typedef struct _IDENMerkleTree
{
	uintptr_t handle;
} IDENMerkleTree;

typedef enum
{
	IDENSTATUSCODE_ERROR,
	IDENSTATUSCODE_NIL_POINTER,
	IDENSTATUSCODE_OUT_OF_MEMORY,
	IDENSTATUSCODE_GENESIS_ID_ERROR,
	IDENSTATUSCODE_MERKLE_TREE_ERROR,
	IDENSTATUSCODE_MERKLE_TREE_HASH_ERROR,
	IDENSTATUSCODE_PROOF_GENERATION_ERROR,
	IDENSTATUSCODE_CLAIM_ERROR,
	IDENSTATUSCODE_IDEN3CREDENTIAL_PARSE_ERROR,
	IDENSTATUSCODE_GET_FIELD_SLOT_INDEX_ERROR,
	IDENSTATUSCODE_POSEIDON_ERROR,
} IDENStatusCode;

typedef struct _IDENStatus
{
	IDENStatusCode status;
	char *error_msg;
} IDENStatus;

typedef struct _IDENProof
{
	bool existence;
	unsigned char **siblings; // array of pointers to hash — 32 byte arrays
	size_t siblings_num; // number of hashes in hashes
	unsigned char *auxNodeKey; // 32 byte array
	unsigned char *auxNodeValue; // 32 byte array
} IDENProof;

typedef struct _IDENClaim
{
	uintptr_t handle;
} IDENClaim;

typedef struct _IDENMerkleTreeHash
{
	unsigned char data[IDEN_MT_HASH_SIZE];
} IDENMerkleTreeHash;

typedef struct _IDENId
{
	unsigned char data[IDEN_ID_SIZE];
} IDENId;

typedef struct _IDENBJJSignature
{
	unsigned char data[IDEN_BJJ_SIGNATURE_SIZE];
} IDENBJJSignature;

typedef struct _IDENTreeState {
	IDENMerkleTreeHash state;
	IDENMerkleTreeHash claims_root;
	IDENMerkleTreeHash revocation_root;
	IDENMerkleTreeHash root_of_roots;
} IDENTreeState;

typedef struct _IDENRevocationStatus
{
	IDENTreeState tree_state;
	IDENProof *proof;
} IDENRevocationStatus;

typedef struct _IDENCircuitsBJJSignatureProof
{
	IDENId issuer_id;
	IDENBJJSignature signature;
	IDENTreeState issuer_tree_state;
	IDENClaim *issuer_auth_claim;
	IDENProof *issuer_auth_claim_mtp;
	IDENRevocationStatus issuer_auth_non_rev_proof;
} IDENCircuitsBJJSignatureProof;

typedef struct _IDENCircuitsClaim
{
	IDENClaim *core_claim;
	IDENTreeState tree_state;
	IDENId issuer_id;
	IDENProof *proof;
	IDENRevocationStatus non_rev_proof;
	IDENCircuitsBJJSignatureProof signature_proof;
} IDENCircuitClaim;

typedef struct _IDENQuery
{
	int slot_index;
	IDENBigInt **values;
	size_t values_num;
	int operator;
} IDENQuery;

typedef struct _IDENAtomicQueryMTPInputs
{
	IDENId id;
	IDENCircuitClaim auth_claim;
	IDENBigInt *challenge;
	IDENBJJSignature signature;

	IDENCircuitClaim claim;

	time_t current_timestamp;

	IDENQuery query;
} IDENAtomicQueryMTPInputs;

// go-circuits:AtomicQuerySigInputs
typedef struct _IDENAtomicQuerySigInputs
{
	IDENId id;
	IDENCircuitClaim auth_claim;
	IDENBigInt *challenge;
	IDENBJJSignature signature;

	IDENCircuitClaim claim;

	IDENQuery query;

	time_t current_timestamp;
} IDENAtomicQuerySigInputs;

typedef struct _IDENAuthInputs
{
	IDENId id;

	IDENCircuitClaim auth_claim;

	IDENBJJSignature signature;
	IDENBigInt *challenge;
} IDENAuthInputs;

typedef struct _IDENByteArray
{
	unsigned char *data;
	size_t data_len;
} IDENByteArray;

typedef struct _IDENMtStorage IDENMtStorage;

typedef bool (*IDENMtStorageFnGetNode)(
	void *ctx, IDENByteArray key, IDENByteArray *value);
typedef bool (*IDENMtStorageFnPutNode)(
	void *ctx, IDENByteArray key, IDENByteArray value);
typedef bool (*IDENMtStorageFnGetRoot)(
	void *ctx, IDENByteArray *hash);
typedef bool (*IDENMtStorageFnSetRoot)(
	void *ctx, IDENByteArray hash);

struct _IDENMtStorage {
    void *ctx;
	IDENMtStorageFnGetNode get_node;
	IDENMtStorageFnPutNode put_node;
	IDENMtStorageFnGetRoot get_root;
	IDENMtStorageFnSetRoot set_root;
};

extern unsigned char **iden_alloc_hashes(int n);

extern void
iden_set_hash_idx(unsigned char **hashes, unsigned char *hash, int idx);

extern void
iden_free_hashes(unsigned char **hashes, size_t num);

unsigned char *
iden_get_hash_at_idx(unsigned char **hashes, int idx);

void *
_iden_get_ptr_by_idx(void **data, int idx);

typedef const char cchar_t;

static inline bool
bridge_mt_storage_get_node(IDENMtStorageFnGetNode fn,
	void *ctx, IDENByteArray key, IDENByteArray *value) {
	return fn(ctx, key, value);
}

static inline bool
bridge_mt_storage_put_node(IDENMtStorageFnPutNode fn,
	void *ctx, IDENByteArray key, IDENByteArray value) {
	return fn(ctx, key, value);
}

static inline bool
bridge_mt_storage_get_root(IDENMtStorageFnGetRoot fn, void *ctx,
	IDENByteArray *hash) {
	return fn(ctx, hash);
}

static inline bool
bridge_mt_storage_set_root(IDENMtStorageFnSetRoot fn, void *ctx,
	IDENByteArray hash) {
	return fn(ctx, hash);
}

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt32 GoInt;
typedef GoUint32 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_32_bit_pointer_matching_GoInt[sizeof(void*)==32/8 ? 1:-1];

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef _GoString_ GoString;
#endif
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


// calculate hashes of claim's index and value and write them to
// indexHash and valueHash appropriately. If any of pointers is NULL,
// do not write this hash. Return true on success or false on error and write
// error to status if it is not NULL.
//
extern GoUint8 IDENClaimTreeEntryHash(IDENMerkleTreeHash* indexHash, IDENMerkleTreeHash* valueHash, IDENClaim* claim, IDENStatus** status);
extern GoUint8 IDENMerkleTreeEntryHash(IDENMerkleTreeHash* indexHash, IDENMerkleTreeHash* valueHash, IDENMerkleTreeEntry* treeEntry, IDENStatus** status);
extern GoUint8 IDENNewMerkleTree(IDENMerkleTree** merkleTree, int maxLevels, IDENStatus** status);
extern GoUint8 IDENNewMerkleTreeWithStorage(IDENMerkleTree** merkleTree, int maxLevels, IDENMtStorage* storage, IDENStatus** status);

// Free memory used by merkle tree
//
extern void IDENFreeMerkleTree(IDENMerkleTree* mt);
extern GoUint8 IDENMerkleTreeAddClaim(IDENMerkleTree* merkleTree, IDENClaim* claim, IDENStatus** status);
extern GoUint8 IDENMerkleTreeAddEntry(IDENMerkleTree* merkleTree, IDENMerkleTreeEntry* entry, IDENStatus** status);
extern GoUint8 IDENMerkleTreeAddKeyValue(IDENMerkleTree* merkleTree, IDENMerkleTreeHash key, IDENMerkleTreeHash value, IDENStatus** status);

// Write root if merkle tree `mt` to `hash`
// Return true on success.
//
extern GoUint8 IDENMerkleTreeRoot(IDENMerkleTreeHash* hash, IDENMerkleTree* mt, IDENStatus** status);

// IDENMerkleTreeGenerateProof allocates new IDENProof and return
// true on success. On failure, return false and write error to status if
// it is not nil.
//
extern GoUint8 IDENMerkleTreeGenerateProof(IDENProof** proof, IDENMerkleTree* mt, IDENMerkleTreeHash indexHash, IDENStatus** status);

// IDENNewProofFromJson unmarshal json string to IDENProof and return
// true on success. On failure, return false and write error to status if
// it is not nil.
//
extern GoUint8 IDENNewProofFromJson(IDENProof** proof, char* jsonStr, IDENStatus** status);
extern void IDENFreeProof(IDENProof* proof);

// Calculate genesis ID from state and write it to pre-allocated `id`.
// state must be a valid IDENMerkleTreeHash in field or function panics.
// If status is not NULL, allocate status and write error message there.
// Return true on success of false otherwise. In case of error, write error
// to status if it is not NULL.
//
extern GoUint8 IDENidGenesisFromIdenState(IDENId* id, IDENMerkleTreeHash state, IDENStatus** status);
extern void IDENFreeStatus(IDENStatus* status);
extern GoUint8 IDENBigIntFromString(IDENBigInt** bigInt, char* bigIntStr, IDENStatus** status);

// Creates new IDENBigInt from hex string. Hex string must be in
// little endian representation of integer.
//
extern GoUint8 IDENBigIntFromHex(IDENBigInt** bigInt, char* bigIntHex, IDENStatus** status);
extern void IDENFreeBigInt(IDENBigInt* bi);
extern GoUint8 IDENNewClaim(IDENClaim** claim, unsigned char* schemaHash, IDENStatus** status);
extern GoUint8 IDENNewClaimFromJSON(IDENClaim** claim, char* jsonStr, IDENStatus** status);
extern GoUint8 IDENClaimSetValueDataInt(IDENClaim* c, IDENBigInt* slotA, IDENBigInt* slotB, IDENStatus** status);
extern GoUint8 IDENClaimSetIndexDataInt(IDENClaim* c, IDENBigInt* slotA, IDENBigInt* slotB, IDENStatus** status);
extern GoUint8 IDENClaimSetIndexID(IDENClaim* c, IDENId id, IDENStatus** status);
extern GoUint8 IDENClaimSetRevocationNonce(IDENClaim* c, long long unsigned int revNonce, IDENStatus** status);
extern GoUint8 IDENClaimSetRevocationNonceAsBigInt(IDENClaim* c, IDENBigInt* revNonce, IDENStatus** status);
extern GoUint8 IDENClaimSetExpirationDate(IDENClaim* c, time_t t, IDENStatus** status);
extern GoUint8 IDENClaimTreeEntry(IDENMerkleTreeEntry* treeEntry, IDENClaim* claim, IDENStatus** status);
extern void IDENFreeClaim(IDENClaim* claim);
extern GoUint8 IDENPrepareAtomicQueryMTPInputs(char** jsonResponse, IDENAtomicQueryMTPInputs* in, IDENStatus** status);
extern GoUint8 IDENPrepareAtomicQuerySigInputs(char** jsonResponse, IDENAtomicQuerySigInputs* in, IDENStatus** status);
extern GoUint8 IDENPrepareAuthInputs(char** response, IDENAuthInputs* in, IDENStatus** status);
extern GoUint8 IDENCalculateGenesisID(IDENId* id, IDENMerkleTreeHash clr, IDENStatus** status);
extern GoUint8 IDENHashOfHashes(IDENMerkleTreeHash* dst, IDENMerkleTreeHash** hashes, size_t n, IDENStatus** status);
extern void IDENHashFromUInt64(IDENMerkleTreeHash* dst, long long unsigned int i);
extern GoUint8 IDENHashFromBigInt(IDENMerkleTreeHash* dst, IDENBigInt* i, IDENStatus** status);
extern GoUint8 IDENHashFromHex(IDENMerkleTreeHash* dst, cchar_t* hexStr, IDENStatus** status);
extern GoUint8 IDENJsonLDParseClaim(IDENClaim** claim, char* credential, char* schema, IDENStatus** status);
extern GoUint8 IDENJsonLDGetFieldSlotIndex(int* slotIndex, char* field, char* claimType, char* schema, IDENStatus** status);
extern GoUint8 IDENIdFromString(IDENId* id, char* idStr, IDENStatus** status);
extern GoUint8 IDENCircuitsBJJSignatureProofFromJson(IDENCircuitsBJJSignatureProof** proof, char* jsonStr, IDENStatus** status);
extern void IDENFreeCircuitsBJJSignatureProof(IDENCircuitsBJJSignatureProof* p);
extern GoUint8 IDENHashInts(IDENBigInt** hash, size_t n, IDENBigInt** ints, IDENStatus** status);

#ifdef __cplusplus
}
#endif
