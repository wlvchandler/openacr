## dmmeta.fcurs - Request generation of custom cursor
<a href="#dmmeta-fcurs"></a>

Some AMC cursors are generated by default. Others have to be requested by the user.
Example:
```
dmmeta.fcurs  fcurs:atf_amc.FDb.cd_typed/delcurs         comment:""
```

See [curstype](/txt/ssimdb/amcdb/curstype.md) for the list of known cursor types.

The following cursors are generated by default:
```
inline-command: acr tcurs -where dflt:Y | ssimfilt ^ -t
TFUNC           DFLT  COMMENT
Atree.curs      Y
Bheap.curs      Y
Bitset.bitcurs  Y
Inlary.curs     Y
Lary.curs       Y
Llist.curs      Y
Ptrary.curs     Y
Tary.curs       Y
Varlen.curs     Y

```

The following cursors can be generated on demand:
```
inline-command: acr tcurs -where dflt:N | ssimfilt ^ -t
TFUNC            DFLT  COMMENT
Bheap.unordcurs  N
Llist.delcurs    N
Ptrary.oncecurs  N
Thash.curs       N

```

### Attributes
<a href="#attributes"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:Attributes -->
* [ctype:](/txt/ssimdb/dmmeta/ctype.md)dmmeta.Fcurs

* file:[data/dmmeta/fcurs.ssim](/data/dmmeta/fcurs.ssim)

italicised fields: *field, ctype, curstype* are [**fldfunc**](/txt/ssim.md#fldfunc) fields

|Field|[Type](/txt/ssimdb/dmmeta/ctype.md)|[Reftype](/txt/ssimdb/dmmeta/reftype.md)|Default|Comment|
|---|---|---|---|---|
|fcurs|[algo.Smallstr50](/txt/protocol/algo/README.md#algo-smallstr50)|[Val](/txt/exe/amc/reftypes.md#val)|||
|*field*|*[dmmeta.Field](/txt/ssimdb/dmmeta/field.md)*|*[Pkey](/txt/exe/amc/reftypes.md#pkey)*||*<br>/RL of fcurs*|
|*ctype*|*[dmmeta.Ctype](/txt/ssimdb/dmmeta/ctype.md)*|*[Pkey](/txt/exe/amc/reftypes.md#pkey)*||*<br>/RL.RL of fcurs*|
|*curstype*|*[amcdb.Curstype](/txt/ssimdb/amcdb/curstype.md)*|*[Pkey](/txt/exe/amc/reftypes.md#pkey)*||*<br>/RR of fcurs*|
|comment|[algo.Comment](/txt/protocol/algo/Comment.md)|[Val](/txt/exe/amc/reftypes.md#val)|||

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:Attributes -->

### Used In Executables
<a href="#used-in-executables"></a>
<!-- dev.mdmark  mdmark:MDSECTION  state:BEG_AUTO  param:ImdbUses -->

* [amc](/txt/exe/amc/internals.md) as [amc.FFcurs](/txt/exe/amc/internals.md#amc-ffcurs)

<!-- dev.mdmark  mdmark:MDSECTION  state:END_AUTO  param:ImdbUses -->

