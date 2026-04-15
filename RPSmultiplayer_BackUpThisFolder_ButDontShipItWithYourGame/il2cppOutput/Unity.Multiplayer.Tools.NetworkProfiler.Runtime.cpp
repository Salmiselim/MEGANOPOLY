#include "pch-cpp.hpp"





template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct GenericInterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

struct Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11;
struct Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079;
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
struct IMetric_1_t8F3766528C5B0E2926E3057F350A597F6EBAC43F;
struct IReadOnlyDictionary_2_t7E602F68B800E9FD97AE5462BAAEB2B2A0A6A6FD;
struct IReadOnlyDictionary_2_t1C9E4278DD0992BFB53341CF2B1D31E871D5CB59;
struct IReadOnlyDictionary_2_t727071262B8B87C9F1C794CCE7F03282F35F8F4C;
struct IReadOnlyDictionary_2_tC190C0DF3FC65E46AC2382576C1FF9A793C41951;
struct IReadOnlyList_1_tACBB2E1C257871194507D0C10E16FD03C486E45A;
struct IReadOnlyList_1_t2624E5B5BBC9D9A1FFFACBF3FD785FE9B2DCB1D4;
struct IReadOnlyList_1_tEE79F46763FDCAE2D53E4F53B6DC0462B18BBE11;
struct IReadOnlyList_1_tA7C793DE0DF6EC6C43210A7A4D208E387820F231;
struct IReadOnlyList_1_tB6DEE144A64A92F4E9A164A303BAAE77F9FDC88B;
struct IReadOnlyList_1_t9015CD3F47392FD89AF0421F2B26138176B189F6;
struct IReadOnlyList_1_t1929F811B7CCB181E3E63A5CE8B87E26B96D7C87;
struct IReadOnlyList_1_tEAB401149CD2FD42A9E63BAD2005A59CDEBE53BF;
struct IReadOnlyList_1_tA4F6B76B3A21A467CF14033008CC40B1001E32F4;
struct IReadOnlyList_1_t0D04E8F00455B7B791CC81FDC30D28B83597F2FD;
struct IReadOnlyList_1_tDDD7E1C7BA89BBDDFC4FAEBA569AADE661814F58;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03;
struct CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct ICounter_tE38FA14E302A126F1FC00B75B0BE81B2899E76A5;
struct ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D;
struct IMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258;
struct INetworkAdapter_t1B8B28814CB6D39490CB0434F38E297A75B46AF0;
struct MethodInfo_t;
struct MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16;
struct MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA;
struct MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0;
struct MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172;
struct MetricFactory_tD1472F5A6AC3B2A052EBDE1E022152830B518E14;
struct NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E;
struct ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3;
struct String_t;
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tBA5ACE5D46C24BFD43FDEEBFCC65AAC587B53479;
struct UnsubscribeFromAllAdapters_t2C59AA45D1C66736C7F8B20FD0A85FF292D43CD3;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DirectedMetricTypeExtensions_t368DEC67A1D713C796EFBD53D90D272061943079_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICounter_tE38FA14E302A126F1FC00B75B0BE81B2899E76A5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMetric_1_t8F3766528C5B0E2926E3057F350A597F6EBAC43F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NetworkAdapters_t920951156C811E1CA3946E5BC7885C8D51C9D1E2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863____0FD040CAF17B3838D226FC959FADFEDA60BC33A7DF10E12E14236D5B4354076D_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863____49F23B36053E8648C11C8FCDD6218E8A9486360FFE3BA98ED7B7F4131100B754_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral1538A07424430301B159B5CE5821E6993791EE42;
IL2CPP_EXTERN_C String_t* _stringLiteral2732277E9D8A4846B7023B9ABCA3C260EFCD3ABA;
IL2CPP_EXTERN_C String_t* _stringLiteral44EE6C16B361AF984DE871897FDED43002CA0C67;
IL2CPP_EXTERN_C String_t* _stringLiteral881CFDF35EA59A6A902F74DFC7CD5D24039ECC88;
IL2CPP_EXTERN_C String_t* _stringLiteral9AFD7D1866B24741AF70BA5BC7A596B8D4710B10;
IL2CPP_EXTERN_C String_t* _stringLiteralBEFA0761F62E788ABF8AA2FED23A4C073F0BFAC8;
IL2CPP_EXTERN_C String_t* _stringLiteralDCED23E1213A3021436B3BC46D18A3C173E15BD2;
IL2CPP_EXTERN_C String_t* _stringLiteralDF6F7FF07E4FC2B4634134C15CFB28E58F405274;
IL2CPP_EXTERN_C String_t* _stringLiteralF7B4990D9AE3010693EE63F2E120DFD72243DFDC;
IL2CPP_EXTERN_C const RuntimeMethod* INetworkAdapter_GetComponent_TisIMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_m7765E89563B9852071A89ABE8C094E3A4155D645_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ProfilerAdapterEventListener_OnAdapterAdded_mE8FFB57D503CDB4FEB9BB80A62C489436689CD71_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ProfilerAdapterEventListener_OnAdapterRemoved_m2D96FF92DE1111A3CAB6B07E1852C80C1B03A6BB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ProfilerAdapterEventListener_OnMetricsReceived_m23E7098C67648C4CC541351C6ADEA74C638C6D97_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_tC31A2036100965F301C42B388772D5A31720F65E 
{
};
struct U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863  : public RuntimeObject
{
};
struct ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03  : public RuntimeObject
{
};
struct EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD  : public RuntimeObject
{
};
struct FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D  : public RuntimeObject
{
};
struct MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16  : public RuntimeObject
{
	RuntimeObject* ___m_SentCounter;
	RuntimeObject* ___m_ReceivedCounter;
	String_t* ___U3CSentU3Ek__BackingField;
	String_t* ___U3CReceivedU3Ek__BackingField;
};
struct MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA  : public RuntimeObject
{
	RuntimeObject* ___m_Counters;
	RuntimeObject* ___m_Gauges;
	RuntimeObject* ___m_Timers;
	RuntimeObject* ___m_PayloadEvents;
	RuntimeObject* ___U3CMetricsU3Ek__BackingField;
	uint64_t ___U3CConnectionIdU3Ek__BackingField;
};
struct MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0  : public RuntimeObject
{
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* ___Bytes;
	MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* ___Events;
};
struct MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172  : public RuntimeObject
{
	String_t* ___U3CSentU3Ek__BackingField;
	RuntimeObject* ___m_SentCounter;
	String_t* ___U3CReceivedU3Ek__BackingField;
	RuntimeObject* ___m_ReceivedCounter;
};
struct NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E  : public RuntimeObject
{
	MetricFactory_tD1472F5A6AC3B2A052EBDE1E022152830B518E14* ___m_MetricFactory;
};
struct ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3  : public RuntimeObject
{
};
struct ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3  : public RuntimeObject
{
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* ___totalBytes;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___rpc;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___namedMessage;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___unnamedMessage;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___networkVariableDelta;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___objectSpawned;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___objectDestroyed;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___serverLog;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___sceneEvent;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___ownershipChange;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___customMessage;
	MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ___networkMessage;
	RuntimeObject* ___m_ByteCounterFactory;
	RuntimeObject* ___m_EventCounterFactory;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tBA5ACE5D46C24BFD43FDEEBFCC65AAC587B53479  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Guid_t 
{
	int32_t ____a;
	int16_t ____b;
	int16_t ____c;
	uint8_t ____d;
	uint8_t ____e;
	uint8_t ____f;
	uint8_t ____g;
	uint8_t ____h;
	uint8_t ____i;
	uint8_t ____j;
	uint8_t ____k;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C 
{
	int32_t ___U3CTypeIndexU3Ek__BackingField;
	int32_t ___U3CEnumValueU3Ek__BackingField;
};
#pragma pack(push, tp, 1)
struct ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					uint16_t ___m_CategoryId;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint16_t ___m_CategoryId_forAlignmentOnly;
				};
			};
		};
		uint8_t ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC__padding[2];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct ProfilerMarkerData_tC01B15D61B904B700E4DE1FFB3452F2C5C2789A2 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					uint8_t ___Type;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint8_t ___Type_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___reserved0_OffsetPadding[1];
					uint8_t ___reserved0;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___reserved0_OffsetPadding_forAlignmentOnly[1];
					uint8_t ___reserved0_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___reserved1_OffsetPadding[2];
					uint16_t ___reserved1;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___reserved1_OffsetPadding_forAlignmentOnly[2];
					uint16_t ___reserved1_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Size_OffsetPadding[4];
					uint32_t ___Size;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Size_OffsetPadding_forAlignmentOnly[4];
					uint32_t ___Size_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___Ptr_OffsetPadding[8];
					void* ___Ptr;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___Ptr_OffsetPadding_forAlignmentOnly[8];
					void* ___Ptr_forAlignmentOnly;
				};
			};
		};
		uint8_t ProfilerMarkerData_tC01B15D61B904B700E4DE1FFB3452F2C5C2789A2__padding[16];
	};
};
#pragma pack(pop, tp)
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D1334_t84F2B8121DA852FFEE3922948959B68B2A10ABD7 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D1334_t84F2B8121DA852FFEE3922948959B68B2A10ABD7__padding[1334];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D761_tB8A9A46CFCC36C3B033EF65A02782CB7FE594665 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D761_tB8A9A46CFCC36C3B033EF65A02782CB7FE594665__padding[761];
	};
};
#pragma pack(pop, tp)
struct MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___FilePathsData;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	bool ___IsEditorOnly;
};
struct MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_pinvoke
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_com
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 
{
	intptr_t ___m_Ptr;
	uint8_t ___m_Type;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct DirectedMetricType_t8380185F845DC7DF921E894038775B9FED5F61B3 
{
	int32_t ___value__;
};
struct MarkerFlags_t58228A99AC6567F565911ED792189DBBDFF83E30 
{
	uint16_t ___value__;
};
struct MetricType_tC5F0E091F07D78F3A079670E9EA599D3D6D690C5 
{
	int32_t ___value__;
};
struct ProfilerMarkerDataUnit_t541C3F1456660AC98D107E8F64DA0E613A2F7753 
{
	uint8_t ___value__;
};
struct RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 
{
	intptr_t ___value;
};
struct NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E  : public RuntimeObject
{
	ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 ___m_Counter;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11  : public MulticastDelegate_t
{
};
struct Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079  : public MulticastDelegate_t
{
};
struct UnsubscribeFromAllAdapters_t2C59AA45D1C66736C7F8B20FD0A85FF292D43CD3  : public MulticastDelegate_t
{
};
struct U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863_StaticFields
{
	__StaticArrayInitTypeSizeU3D761_tB8A9A46CFCC36C3B033EF65A02782CB7FE594665 ___0FD040CAF17B3838D226FC959FADFEDA60BC33A7DF10E12E14236D5B4354076D;
	__StaticArrayInitTypeSizeU3D1334_t84F2B8121DA852FFEE3922948959B68B2A10ABD7 ___49F23B36053E8648C11C8FCDD6218E8A9486360FFE3BA98ED7B7F4131100B754;
};
struct FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_StaticFields
{
	Guid_t ___NetworkProfilerGuid;
};
struct ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_StaticFields
{
	bool ___s_Initialized;
	NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E* ___s_NetStatSerializer;
};
struct ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_StaticFields
{
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* ___s_Singleton;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Guid_t_StaticFields
{
	Guid_t ___Empty;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_gshared_inline (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* __this, ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC ___0_category, String_t* ___1_name, uint8_t ___2_dataUnit, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_gshared_inline (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* __this, int64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A_gshared (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A_gshared (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA_gshared (NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7_gshared (Guid_t ___0_id, int32_t ___1_tag, NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF ___2_data, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t ProfilerUtility_GetProfilerMarkerDataType_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_mFEA9A9D2DBAF423513797DF56A48F9E1B18A9DF2_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m9712F6405A5D5C4128EAFA7860A222DE388ED6C5_gshared_inline (const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B (RuntimeArray* ___0_array, RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 ___1_fldHandle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC ProfilerCategory_get_Network_m4932239B021D1A289BC102F3ECBE36922B14EA93 (const RuntimeMethod* method) ;
inline void ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_inline (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* __this, ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC ___0_category, String_t* ___1_name, uint8_t ___2_dataUnit, const RuntimeMethod* method)
{
	((  void (*) (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945*, ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC, String_t*, uint8_t, const RuntimeMethod*))ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_gshared_inline)(__this, ___0_category, ___1_name, ___2_dataUnit, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CounterWrapper__ctor_m37735EED16E0349741D489482253790D47C864C2 (CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E* __this, ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 ___0_counter, const RuntimeMethod* method) ;
inline void ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_inline (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* __this, int64_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945*, int64_t, const RuntimeMethod*))ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_gshared_inline)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricByteCounters_get_Sent_mC97D8190FB75086A6566747A73E5CEA1EECFB4E6_inline (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricByteCounters_get_Received_m59C838195C22C352ABA8D7F0AB49FC09ED7E93F2_inline (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricByteCounters__ctor_m44351F0FF084F187182477B4DD7F7EE19DD0F023 (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, String_t* ___0_displayName, RuntimeObject* ___1_counterFactory, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricEventCounters__ctor_m34751E1F30D66C6D45690621898DD0DC3D467C15 (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, String_t* ___0_displayName, RuntimeObject* ___1_counterFactory, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricEventCounters_get_Sent_m78BE5E723C71AB0CAAF3BBC0F5FDC6DC35871D7F_inline (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricEventCounters_get_Received_m8B0522797455165C4CA584D2351D008182DF0C42_inline (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerCounters__ctor_m98EDA29C1F0F4B614803C8E0B7FC86342E0CAC84 (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, RuntimeObject* ___0_byteCounterFactory, RuntimeObject* ___1_eventCounterFactory, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ByteCounterFactory__ctor_mA8E17E6D3EA7E058CE93D4DC9DC14BC1B022E1D6 (ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCounterFactory__ctor_m06A4FB7FBE5FEDFA31B6D6C5CE0D37E774A9E6B3 (EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* ProfilerCounters_ConstructMetricByteCounters_m5F1E1E208D3ADE2E551FBC1E79152D2183792710 (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90 (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, int32_t ___0_metricType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ProfilerCounters_ConstructMetricCounters_mC8C2650935AE7D7EE0D603A3AFA89C76CE3BC3FC (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MetricTypeExtensions_GetDisplayNameString_mB9E62BEA967B432D1FD19797ECF7E2E6FAB4086B (int32_t ___0_metricType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters__ctor_m43C1A8C767A6A90CAC226CDCAE69A34BF1F71B7B (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, String_t* ___0_displayName, RuntimeObject* ___1_byteCounterFactory, RuntimeObject* ___2_eventCounterFactory, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836 (int32_t ___0_directedMetric, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MetricCollection_TryGetCounter_m002A9388A45AA9562FAF9DA9C81AE6DAF2C7C07A (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* __this, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___0_metricId, RuntimeObject** ___1_counter, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricByteCounters_Sample_m1927F17A64286D9EAEA1B63ED92C86FB09CE7045 (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, int64_t ___0_sent, int64_t ___1_received, const RuntimeMethod* method) ;
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1 (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4 (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0 (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89 (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155 (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155_gshared)(__this, ___0_sent, ___1_received, method);
}
inline RuntimeObject* MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C ___1_metricId, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA*, MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C, const RuntimeMethod*))MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A_gshared)(___0_collection, ___1_metricId, method);
}
inline void MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, RuntimeObject* ___0_sent, RuntimeObject* ___1_received, const RuntimeMethod* method)
{
	((  void (*) (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A_gshared)(__this, ___0_sent, ___1_received, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Guid__ctor_mAE66BA1C43B4194F4F7991E2E30370E36CBBF830 (Guid_t* __this, String_t* ___0_g, const RuntimeMethod* method) ;
inline void Action_1__ctor_m3880508FAD3D34B163F6EBF8E1292EDC8BC3BA11 (Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared)(__this, ___0_object, ___1_method, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsubscribeFromAllAdapters_t2C59AA45D1C66736C7F8B20FD0A85FF292D43CD3* NetworkAdapters_SubscribeToAll_m723AC3FD21865EC093EA0E18E00007642790850A (Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11* ___0_subscribeToAdapter, Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11* ___1_unsubscribeFromAdapter, const RuntimeMethod* method) ;
inline void Action_1__ctor_m4F86B44384B4643D150CD9065F7B672056D27145 (Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared)(__this, ___0_object, ___1_method, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener_PopulateProfilerIfEnabled_mA1EE8D6408312BC481F95A8E9E91E17B23EEAA23 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* ProfilerCounters_get_Instance_m55A0FA5692DC4C5C6E0E37A8C247DAE78328383B (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerCounters_UpdateFromMetrics_mD3171E543D39C1180FD915DF42AD0130628C677E (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF NetStatSerializer_Serialize_mAD36C6DA9699EFCB8EC8D58CDB44A0BEDD0CD9B3 (NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E* __this, MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_metricCollection, const RuntimeMethod* method) ;
inline void NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA (NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF* __this, const RuntimeMethod* method)
{
	((  void (*) (NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF*, const RuntimeMethod*))NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA_gshared)(__this, method);
}
inline void Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7 (Guid_t ___0_id, int32_t ___1_tag, NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF ___2_data, const RuntimeMethod* method)
{
	((  void (*) (Guid_t, int32_t, NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF, const RuntimeMethod*))Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7_gshared)(___0_id, ___1_tag, ___2_data, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetStatSerializer__ctor_m9C4C58C9E498B39BD958D5596470165CC74318F2 (NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E* __this, const RuntimeMethod* method) ;
inline uint8_t ProfilerUtility_GetProfilerMarkerDataType_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_mFEA9A9D2DBAF423513797DF56A48F9E1B18A9DF2 (const RuntimeMethod* method)
{
	return ((  uint8_t (*) (const RuntimeMethod*))ProfilerUtility_GetProfilerMarkerDataType_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_mFEA9A9D2DBAF423513797DF56A48F9E1B18A9DF2_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t ProfilerCategory_op_Implicit_m441AE38B56781EE2D3F0865F65C81A77BEC6D76B (ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC ___0_category, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t ProfilerUnsafeUtility_CreateMarker_mC5E1AAB8CC1F0342065DF85BA3334445ED754E64 (String_t* ___0_name, uint16_t ___1_categoryId, uint16_t ___2_flags, int32_t ___3_metadataCount, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_SetMarkerMetadata_mD5FD13DE489F9C2E0E7D0AF209CD9369375CFA16 (intptr_t ___0_markerPtr, int32_t ___1_index, String_t* ___2_name, uint8_t ___3_type, uint8_t ___4_unit, const RuntimeMethod* method) ;
inline int32_t UnsafeUtility_SizeOf_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m9712F6405A5D5C4128EAFA7860A222DE388ED6C5_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m9712F6405A5D5C4128EAFA7860A222DE388ED6C5_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_SingleSampleWithMetadata_mA4CD442AA9596086004E36704DCE40F8B5D8AC9A (intptr_t ___0_markerPtr, int32_t ___1_metadataCount, void* ___2_metadata, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4 UnitySourceGeneratedAssemblyMonoScriptTypes_v1_Get_m26761998FF53875431A3F3372351DC8EB573789F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863____0FD040CAF17B3838D226FC959FADFEDA60BC33A7DF10E12E14236D5B4354076D_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863____49F23B36053E8648C11C8FCDD6218E8A9486360FFE3BA98ED7B7F4131100B754_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)1334));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_2 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863____49F23B36053E8648C11C8FCDD6218E8A9486360FFE3BA98ED7B7F4131100B754_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_1, L_2, NULL);
		(&V_0)->___FilePathsData = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___FilePathsData), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)761));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_t78BEFB64C5D04F43EE276FA97460B2F8F0B07863____0FD040CAF17B3838D226FC959FADFEDA60BC33A7DF10E12E14236D5B4354076D_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		(&V_0)->___TypesData = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___TypesData), (void*)L_4);
		(&V_0)->___TotalFiles = ((int32_t)11);
		(&V_0)->___TotalTypes = ((int32_t)11);
		(&V_0)->___IsEditorOnly = (bool)0;
		MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4 L_6 = V_0;
		V_1 = L_6;
		goto IL_005f;
	}

IL_005f:
	{
		MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4 L_7 = V_1;
		return L_7;
	}
}
// Method Definition Index: 144038
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnitySourceGeneratedAssemblyMonoScriptTypes_v1__ctor_m53F59AF3D717CE6238BD3E7C3ADB5F9421D7B2A0 (UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tBA5ACE5D46C24BFD43FDEEBFCC65AAC587B53479* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshal_pinvoke(const MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4& unmarshaled, MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_pinvoke& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshal_pinvoke_back(const MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_pinvoke& marshaled, MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshal_pinvoke_cleanup(MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
IL2CPP_EXTERN_C void MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshal_com(const MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4& unmarshaled, MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_com& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshal_com_back(const MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_com& marshaled, MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshal_com_cleanup(MonoScriptData_t10EC088C87702F597E3E4D1DA20BE26DEA28DAC4_marshaled_com& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144039
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ByteCounterFactory_Construct_m8A1A2CC18FB1140AC1D89D0353CEAC82E6B8C282 (ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ByteCounterFactory.cs:8>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ByteCounterFactory.cs:9>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ByteCounterFactory.cs:10>
		ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC L_0;
		L_0 = ProfilerCategory_get_Network_m4932239B021D1A289BC102F3ECBE36922B14EA93(NULL);
		String_t* L_1 = ___0_name;
		ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 L_2;
		memset((&L_2), 0, sizeof(L_2));
		ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_inline((&L_2), L_0, L_1, 2, ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_RuntimeMethod_var);
		CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E* L_3 = (CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E*)il2cpp_codegen_object_new(CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E_il2cpp_TypeInfo_var);
		CounterWrapper__ctor_m37735EED16E0349741D489482253790D47C864C2(L_3, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 144040
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ByteCounterFactory__ctor_mA8E17E6D3EA7E058CE93D4DC9DC14BC1B022E1D6 (ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144041
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CounterWrapper__ctor_m37735EED16E0349741D489482253790D47C864C2 (CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E* __this, ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 ___0_counter, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/CounterWrapper.cs:9>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/CounterWrapper.cs:11>
		ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 L_0 = ___0_counter;
		__this->___m_Counter = L_0;
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/CounterWrapper.cs:12>
		return;
	}
}
// Method Definition Index: 144042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CounterWrapper_Sample_m59073B4F0E40734844C12A7F5D0863CA220FFF7B (CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E* __this, int64_t ___0_inValue, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/CounterWrapper.cs:16>
		ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* L_0 = (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945*)(&__this->___m_Counter);
		int64_t L_1 = ___0_inValue;
		ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_inline(L_0, L_1, ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/CounterWrapper.cs:17>
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* EventCounterFactory_Construct_m03130019B1B30CB13DF4501B9310E029902DE2F2 (EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/EventCounterFactory.cs:8>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/EventCounterFactory.cs:9>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/EventCounterFactory.cs:10>
		ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC L_0;
		L_0 = ProfilerCategory_get_Network_m4932239B021D1A289BC102F3ECBE36922B14EA93(NULL);
		String_t* L_1 = ___0_name;
		ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945 L_2;
		memset((&L_2), 0, sizeof(L_2));
		ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_inline((&L_2), L_0, L_1, 3, ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_RuntimeMethod_var);
		CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E* L_3 = (CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E*)il2cpp_codegen_object_new(CounterWrapper_t66372376907DC445BA05E96ABAC10E760B83319E_il2cpp_TypeInfo_var);
		CounterWrapper__ctor_m37735EED16E0349741D489482253790D47C864C2(L_3, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 144044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventCounterFactory__ctor_m06A4FB7FBE5FEDFA31B6D6C5CE0D37E774A9E6B3 (EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricByteCounters__ctor_m44351F0FF084F187182477B4DD7F7EE19DD0F023 (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, String_t* ___0_displayName, RuntimeObject* ___1_counterFactory, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9AFD7D1866B24741AF70BA5BC7A596B8D4710B10);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDCED23E1213A3021436B3BC46D18A3C173E15BD2);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:11>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:13>
		String_t* L_0 = ___0_displayName;
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_0, _stringLiteralDCED23E1213A3021436B3BC46D18A3C173E15BD2, NULL);
		__this->___U3CSentU3Ek__BackingField = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CSentU3Ek__BackingField), (void*)L_1);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:14>
		String_t* L_2 = ___0_displayName;
		String_t* L_3;
		L_3 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_2, _stringLiteral9AFD7D1866B24741AF70BA5BC7A596B8D4710B10, NULL);
		__this->___U3CReceivedU3Ek__BackingField = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CReceivedU3Ek__BackingField), (void*)L_3);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:16>
		RuntimeObject* L_4 = ___1_counterFactory;
		String_t* L_5;
		L_5 = MetricByteCounters_get_Sent_mC97D8190FB75086A6566747A73E5CEA1EECFB4E6_inline(__this, NULL);
		NullCheck(L_4);
		RuntimeObject* L_6;
		L_6 = InterfaceFuncInvoker1< RuntimeObject*, String_t* >::Invoke(0, ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var, L_4, L_5);
		__this->___m_SentCounter = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_SentCounter), (void*)L_6);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:17>
		RuntimeObject* L_7 = ___1_counterFactory;
		String_t* L_8;
		L_8 = MetricByteCounters_get_Received_m59C838195C22C352ABA8D7F0AB49FC09ED7E93F2_inline(__this, NULL);
		NullCheck(L_7);
		RuntimeObject* L_9;
		L_9 = InterfaceFuncInvoker1< RuntimeObject*, String_t* >::Invoke(0, ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var, L_7, L_8);
		__this->___m_ReceivedCounter = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_ReceivedCounter), (void*)L_9);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:18>
		return;
	}
}
// Method Definition Index: 144048
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MetricByteCounters_get_Sent_mC97D8190FB75086A6566747A73E5CEA1EECFB4E6 (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:20>
		String_t* L_0 = __this->___U3CSentU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144049
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MetricByteCounters_get_Received_m59C838195C22C352ABA8D7F0AB49FC09ED7E93F2 (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:22>
		String_t* L_0 = __this->___U3CReceivedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144051
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricByteCounters_Sample_m1927F17A64286D9EAEA1B63ED92C86FB09CE7045 (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, int64_t ___0_sent, int64_t ___1_received, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICounter_tE38FA14E302A126F1FC00B75B0BE81B2899E76A5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:48>
		RuntimeObject* L_0 = __this->___m_SentCounter;
		int64_t L_1 = ___0_sent;
		NullCheck(L_0);
		InterfaceActionInvoker1< int64_t >::Invoke(0, ICounter_tE38FA14E302A126F1FC00B75B0BE81B2899E76A5_il2cpp_TypeInfo_var, L_0, L_1);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:49>
		RuntimeObject* L_2 = __this->___m_ReceivedCounter;
		int64_t L_3 = ___1_received;
		NullCheck(L_2);
		InterfaceActionInvoker1< int64_t >::Invoke(0, ICounter_tE38FA14E302A126F1FC00B75B0BE81B2899E76A5_il2cpp_TypeInfo_var, L_2, L_3);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:50>
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricCounters__ctor_m43C1A8C767A6A90CAC226CDCAE69A34BF1F71B7B (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* __this, String_t* ___0_displayName, RuntimeObject* ___1_byteCounterFactory, RuntimeObject* ___2_eventCounterFactory, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:11>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:12>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:13>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:14>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:16>
		String_t* L_0 = ___0_displayName;
		RuntimeObject* L_1 = ___1_byteCounterFactory;
		MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* L_2 = (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16*)il2cpp_codegen_object_new(MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16_il2cpp_TypeInfo_var);
		MetricByteCounters__ctor_m44351F0FF084F187182477B4DD7F7EE19DD0F023(L_2, L_0, L_1, NULL);
		__this->___Bytes = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Bytes), (void*)L_2);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:17>
		String_t* L_3 = ___0_displayName;
		RuntimeObject* L_4 = ___2_eventCounterFactory;
		MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* L_5 = (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172*)il2cpp_codegen_object_new(MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172_il2cpp_TypeInfo_var);
		MetricEventCounters__ctor_m34751E1F30D66C6D45690621898DD0DC3D467C15(L_5, L_3, L_4, NULL);
		__this->___Events = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Events), (void*)L_5);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricCounters.cs:18>
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144054
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MetricEventCounters_get_Sent_m78BE5E723C71AB0CAAF3BBC0F5FDC6DC35871D7F (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:7>
		String_t* L_0 = __this->___U3CSentU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144055
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MetricEventCounters_get_Received_m8B0522797455165C4CA584D2351D008182DF0C42 (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:10>
		String_t* L_0 = __this->___U3CReceivedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144056
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MetricEventCounters__ctor_m34751E1F30D66C6D45690621898DD0DC3D467C15 (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, String_t* ___0_displayName, RuntimeObject* ___1_counterFactory, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1538A07424430301B159B5CE5821E6993791EE42);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDF6F7FF07E4FC2B4634134C15CFB28E58F405274);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:13>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:15>
		String_t* L_0 = ___0_displayName;
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_0, _stringLiteral1538A07424430301B159B5CE5821E6993791EE42, NULL);
		__this->___U3CSentU3Ek__BackingField = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CSentU3Ek__BackingField), (void*)L_1);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:16>
		String_t* L_2 = ___0_displayName;
		String_t* L_3;
		L_3 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_2, _stringLiteralDF6F7FF07E4FC2B4634134C15CFB28E58F405274, NULL);
		__this->___U3CReceivedU3Ek__BackingField = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CReceivedU3Ek__BackingField), (void*)L_3);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:18>
		RuntimeObject* L_4 = ___1_counterFactory;
		String_t* L_5;
		L_5 = MetricEventCounters_get_Sent_m78BE5E723C71AB0CAAF3BBC0F5FDC6DC35871D7F_inline(__this, NULL);
		NullCheck(L_4);
		RuntimeObject* L_6;
		L_6 = InterfaceFuncInvoker1< RuntimeObject*, String_t* >::Invoke(0, ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var, L_4, L_5);
		__this->___m_SentCounter = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_SentCounter), (void*)L_6);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:19>
		RuntimeObject* L_7 = ___1_counterFactory;
		String_t* L_8;
		L_8 = MetricEventCounters_get_Received_m8B0522797455165C4CA584D2351D008182DF0C42_inline(__this, NULL);
		NullCheck(L_7);
		RuntimeObject* L_9;
		L_9 = InterfaceFuncInvoker1< RuntimeObject*, String_t* >::Invoke(0, ICounterFactory_tF750668AF4BD2A64BF1BDA6FB3E97ADC1DF3B63D_il2cpp_TypeInfo_var, L_7, L_8);
		__this->___m_ReceivedCounter = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_ReceivedCounter), (void*)L_9);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:20>
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144058
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* ProfilerCounters_get_Instance_m55A0FA5692DC4C5C6E0E37A8C247DAE78328383B (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* G_B2_0 = NULL;
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* G_B1_0 = NULL;
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:9>
		ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* L_0 = ((ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_il2cpp_TypeInfo_var))->___s_Singleton;
		ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_0016;
		}
		G_B1_0 = L_1;
	}
	{
		ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* L_2 = (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3*)il2cpp_codegen_object_new(ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_il2cpp_TypeInfo_var);
		ProfilerCounters__ctor_m98EDA29C1F0F4B614803C8E0B7FC86342E0CAC84(L_2, (RuntimeObject*)NULL, (RuntimeObject*)NULL, NULL);
		ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* L_3 = L_2;
		((ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_il2cpp_TypeInfo_var))->___s_Singleton = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3_il2cpp_TypeInfo_var))->___s_Singleton), (void*)L_3);
		G_B2_0 = L_3;
	}

IL_0016:
	{
		return G_B2_0;
	}
}
// Method Definition Index: 144059
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerCounters__ctor_m98EDA29C1F0F4B614803C8E0B7FC86342E0CAC84 (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, RuntimeObject* ___0_byteCounterFactory, RuntimeObject* ___1_eventCounterFactory, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2732277E9D8A4846B7023B9ABCA3C260EFCD3ABA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral44EE6C16B361AF984DE871897FDED43002CA0C67);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBEFA0761F62E788ABF8AA2FED23A4C073F0BFAC8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF7B4990D9AE3010693EE63F2E120DFD72243DFDC);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* G_B2_0 = NULL;
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* G_B2_1 = NULL;
	RuntimeObject* G_B1_0 = NULL;
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* G_B1_1 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* G_B4_1 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* G_B3_1 = NULL;
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:27>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:28>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:29>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:31>
		RuntimeObject* L_0 = ___0_byteCounterFactory;
		RuntimeObject* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			G_B2_1 = __this;
			goto IL_0013;
		}
		G_B1_0 = L_1;
		G_B1_1 = __this;
	}
	{
		ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03* L_2 = (ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03*)il2cpp_codegen_object_new(ByteCounterFactory_t77A05E9859E185C56FFAA6829EC3D5C45272DF03_il2cpp_TypeInfo_var);
		ByteCounterFactory__ctor_mA8E17E6D3EA7E058CE93D4DC9DC14BC1B022E1D6(L_2, NULL);
		G_B2_0 = ((RuntimeObject*)(L_2));
		G_B2_1 = G_B1_1;
	}

IL_0013:
	{
		NullCheck(G_B2_1);
		G_B2_1->___m_ByteCounterFactory = G_B2_0;
		Il2CppCodeGenWriteBarrier((void**)(&G_B2_1->___m_ByteCounterFactory), (void*)G_B2_0);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:32>
		RuntimeObject* L_3 = ___1_eventCounterFactory;
		RuntimeObject* L_4 = L_3;
		if (L_4)
		{
			G_B4_0 = L_4;
			G_B4_1 = __this;
			goto IL_0023;
		}
		G_B3_0 = L_4;
		G_B3_1 = __this;
	}
	{
		EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD* L_5 = (EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD*)il2cpp_codegen_object_new(EventCounterFactory_tB381B04E06434F06171FC4594BFF08F8332A0CAD_il2cpp_TypeInfo_var);
		EventCounterFactory__ctor_m06A4FB7FBE5FEDFA31B6D6C5CE0D37E774A9E6B3(L_5, NULL);
		G_B4_0 = ((RuntimeObject*)(L_5));
		G_B4_1 = G_B3_1;
	}

IL_0023:
	{
		NullCheck(G_B4_1);
		G_B4_1->___m_EventCounterFactory = G_B4_0;
		Il2CppCodeGenWriteBarrier((void**)(&G_B4_1->___m_EventCounterFactory), (void*)G_B4_0);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:34>
		MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* L_6;
		L_6 = ProfilerCounters_ConstructMetricByteCounters_m5F1E1E208D3ADE2E551FBC1E79152D2183792710(__this, _stringLiteral44EE6C16B361AF984DE871897FDED43002CA0C67, NULL);
		__this->___totalBytes = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___totalBytes), (void*)L_6);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:35>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_7;
		L_7 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, 2, NULL);
		__this->___rpc = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___rpc), (void*)L_7);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:36>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_8;
		L_8 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, 3, NULL);
		__this->___namedMessage = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___namedMessage), (void*)L_8);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:37>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_9;
		L_9 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, 4, NULL);
		__this->___unnamedMessage = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___unnamedMessage), (void*)L_9);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:38>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_10;
		L_10 = ProfilerCounters_ConstructMetricCounters_mC8C2650935AE7D7EE0D603A3AFA89C76CE3BC3FC(__this, _stringLiteralBEFA0761F62E788ABF8AA2FED23A4C073F0BFAC8, NULL);
		__this->___networkVariableDelta = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___networkVariableDelta), (void*)L_10);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:39>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_11;
		L_11 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, 6, NULL);
		__this->___objectSpawned = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___objectSpawned), (void*)L_11);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:40>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_12;
		L_12 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, 7, NULL);
		__this->___objectDestroyed = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___objectDestroyed), (void*)L_12);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:41>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_13;
		L_13 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, ((int32_t)9), NULL);
		__this->___serverLog = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___serverLog), (void*)L_13);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:42>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_14;
		L_14 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, ((int32_t)10), NULL);
		__this->___sceneEvent = L_14;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___sceneEvent), (void*)L_14);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:43>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_15;
		L_15 = ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90(__this, 8, NULL);
		__this->___ownershipChange = L_15;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ownershipChange), (void*)L_15);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:44>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_16;
		L_16 = ProfilerCounters_ConstructMetricCounters_mC8C2650935AE7D7EE0D603A3AFA89C76CE3BC3FC(__this, _stringLiteral2732277E9D8A4846B7023B9ABCA3C260EFCD3ABA, NULL);
		__this->___customMessage = L_16;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___customMessage), (void*)L_16);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:45>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_17;
		L_17 = ProfilerCounters_ConstructMetricCounters_mC8C2650935AE7D7EE0D603A3AFA89C76CE3BC3FC(__this, _stringLiteralF7B4990D9AE3010693EE63F2E120DFD72243DFDC, NULL);
		__this->___networkMessage = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___networkMessage), (void*)L_17);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:46>
		return;
	}
}
// Method Definition Index: 144060
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* ProfilerCounters_ConstructMetricByteCounters_m5F1E1E208D3ADE2E551FBC1E79152D2183792710 (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:49>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:50>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:51>
		String_t* L_0 = ___0_name;
		RuntimeObject* L_1 = __this->___m_ByteCounterFactory;
		MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* L_2 = (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16*)il2cpp_codegen_object_new(MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16_il2cpp_TypeInfo_var);
		MetricByteCounters__ctor_m44351F0FF084F187182477B4DD7F7EE19DD0F023(L_2, L_0, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 144061
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ProfilerCounters_ConstructMetricCounters_m7A5BC7EB97AE5A9EA28998EC5DB296A6943CAB90 (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, int32_t ___0_metricType, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:54>
		int32_t L_0 = ___0_metricType;
		String_t* L_1;
		L_1 = MetricTypeExtensions_GetDisplayNameString_mB9E62BEA967B432D1FD19797ECF7E2E6FAB4086B(L_0, NULL);
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_2;
		L_2 = ProfilerCounters_ConstructMetricCounters_mC8C2650935AE7D7EE0D603A3AFA89C76CE3BC3FC(__this, L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 144062
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* ProfilerCounters_ConstructMetricCounters_mC8C2650935AE7D7EE0D603A3AFA89C76CE3BC3FC (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:56>
		String_t* L_0 = ___0_name;
		RuntimeObject* L_1 = __this->___m_ByteCounterFactory;
		RuntimeObject* L_2 = __this->___m_EventCounterFactory;
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_3 = (MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0*)il2cpp_codegen_object_new(MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0_il2cpp_TypeInfo_var);
		MetricCounters__ctor_m43C1A8C767A6A90CAC226CDCAE69A34BF1F71B7B(L_3, L_0, L_1, L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 144063
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerCounters_UpdateFromMetrics_mD3171E543D39C1180FD915DF42AD0130628C677E (ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* __this, MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DirectedMetricTypeExtensions_t368DEC67A1D713C796EFBD53D90D272061943079_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMetric_1_t8F3766528C5B0E2926E3057F350A597F6EBAC43F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* G_B2_0 = NULL;
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* G_B1_0 = NULL;
	int64_t G_B3_0 = 0;
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* G_B3_1 = NULL;
	int64_t G_B5_0 = 0;
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* G_B5_1 = NULL;
	int64_t G_B4_0 = 0;
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* G_B4_1 = NULL;
	int64_t G_B6_0 = 0;
	int64_t G_B6_1 = 0;
	MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* G_B6_2 = NULL;
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:60>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:61>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:62>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:63>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:64>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:65>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:66>
		MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* L_0 = __this->___totalBytes;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_1 = ___0_collection;
		il2cpp_codegen_runtime_class_init_inline(DirectedMetricTypeExtensions_t368DEC67A1D713C796EFBD53D90D272061943079_il2cpp_TypeInfo_var);
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_2;
		L_2 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(6, NULL);
		NullCheck(L_1);
		bool L_3;
		L_3 = MetricCollection_TryGetCounter_m002A9388A45AA9562FAF9DA9C81AE6DAF2C7C07A(L_1, L_2, (&V_0), NULL);
		if (L_3)
		{
			G_B2_0 = L_0;
			goto IL_001b;
		}
		G_B1_0 = L_0;
	}
	{
		G_B3_0 = ((int64_t)0);
		G_B3_1 = G_B1_0;
		goto IL_0021;
	}

IL_001b:
	{
		RuntimeObject* L_4 = V_0;
		NullCheck(L_4);
		int64_t L_5;
		L_5 = InterfaceFuncInvoker0< int64_t >::Invoke(0, IMetric_1_t8F3766528C5B0E2926E3057F350A597F6EBAC43F_il2cpp_TypeInfo_var, L_4);
		G_B3_0 = L_5;
		G_B3_1 = G_B2_0;
	}

IL_0021:
	{
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_6 = ___0_collection;
		il2cpp_codegen_runtime_class_init_inline(DirectedMetricTypeExtensions_t368DEC67A1D713C796EFBD53D90D272061943079_il2cpp_TypeInfo_var);
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_7;
		L_7 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(5, NULL);
		NullCheck(L_6);
		bool L_8;
		L_8 = MetricCollection_TryGetCounter_m002A9388A45AA9562FAF9DA9C81AE6DAF2C7C07A(L_6, L_7, (&V_1), NULL);
		if (L_8)
		{
			G_B5_0 = G_B3_0;
			G_B5_1 = G_B3_1;
			goto IL_0035;
		}
		G_B4_0 = G_B3_0;
		G_B4_1 = G_B3_1;
	}
	{
		G_B6_0 = ((int64_t)0);
		G_B6_1 = G_B4_0;
		G_B6_2 = G_B4_1;
		goto IL_003b;
	}

IL_0035:
	{
		RuntimeObject* L_9 = V_1;
		NullCheck(L_9);
		int64_t L_10;
		L_10 = InterfaceFuncInvoker0< int64_t >::Invoke(0, IMetric_1_t8F3766528C5B0E2926E3057F350A597F6EBAC43F_il2cpp_TypeInfo_var, L_9);
		G_B6_0 = L_10;
		G_B6_1 = G_B5_0;
		G_B6_2 = G_B5_1;
	}

IL_003b:
	{
		NullCheck(G_B6_2);
		MetricByteCounters_Sample_m1927F17A64286D9EAEA1B63ED92C86FB09CE7045(G_B6_2, G_B6_1, G_B6_0, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:68>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:69>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:70>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_11 = __this->___rpc;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_12 = ___0_collection;
		il2cpp_codegen_runtime_class_init_inline(DirectedMetricTypeExtensions_t368DEC67A1D713C796EFBD53D90D272061943079_il2cpp_TypeInfo_var);
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_13;
		L_13 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)10), NULL);
		RuntimeObject* L_14;
		L_14 = MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029(L_12, L_13, MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_15 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_16;
		L_16 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)9), NULL);
		RuntimeObject* L_17;
		L_17 = MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029(L_15, L_16, MetricsCollectionExtensions_GetEventValues_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m073FF9F81951ECBC82E8329D558F765775359029_RuntimeMethod_var);
		NullCheck(L_11);
		MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1(L_11, L_14, L_17, MetricCounters_Sample_TisRpcEvent_t02957B0FACFEFA736A8043B009FC5D24EF890EDA_m7475E81112BDB0F5D023EBE634CB18BA1C1EC4E1_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:72>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:73>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:74>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_18 = __this->___namedMessage;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_19 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_20;
		L_20 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)14), NULL);
		RuntimeObject* L_21;
		L_21 = MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2(L_19, L_20, MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_22 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_23;
		L_23 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)13), NULL);
		RuntimeObject* L_24;
		L_24 = MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2(L_22, L_23, MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_RuntimeMethod_var);
		NullCheck(L_18);
		MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA(L_18, L_21, L_24, MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:76>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:77>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:78>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_25 = __this->___unnamedMessage;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_26 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_27;
		L_27 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)18), NULL);
		RuntimeObject* L_28;
		L_28 = MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1(L_26, L_27, MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_29 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_30;
		L_30 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)17), NULL);
		RuntimeObject* L_31;
		L_31 = MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1(L_29, L_30, MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_RuntimeMethod_var);
		NullCheck(L_25);
		MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4(L_25, L_28, L_31, MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:81>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:82>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:83>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_32 = __this->___customMessage;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_33 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_34;
		L_34 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)14), NULL);
		RuntimeObject* L_35;
		L_35 = MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2(L_33, L_34, MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_36 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_37;
		L_37 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)13), NULL);
		RuntimeObject* L_38;
		L_38 = MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2(L_36, L_37, MetricsCollectionExtensions_GetEventValues_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m40772A5E04ADDA7B07559FDDA6A63D6F673142A2_RuntimeMethod_var);
		NullCheck(L_32);
		MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA(L_32, L_35, L_38, MetricCounters_Sample_TisNamedMessageEvent_t49461F3ACEB9D8EEF54BD7DAB057EE0E07CCB08C_m28EDC67146EB2608955F94EEF7714F2CF50780FA_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:84>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:85>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:86>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_39 = __this->___customMessage;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_40 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_41;
		L_41 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)18), NULL);
		RuntimeObject* L_42;
		L_42 = MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1(L_40, L_41, MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_43 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_44;
		L_44 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)17), NULL);
		RuntimeObject* L_45;
		L_45 = MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1(L_43, L_44, MetricsCollectionExtensions_GetEventValues_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_mC0B26349C2802FD06004545C88E3708232A295E1_RuntimeMethod_var);
		NullCheck(L_39);
		MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4(L_39, L_42, L_45, MetricCounters_Sample_TisUnnamedMessageEvent_t46FC0EE36E43495452CA9BB2ADB9256D94373220_m9F5AF9549AC2E06FF2E3054DD21652D280BCACE4_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:88>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:89>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:90>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_46 = __this->___networkVariableDelta;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_47 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_48;
		L_48 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)22), NULL);
		RuntimeObject* L_49;
		L_49 = MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036(L_47, L_48, MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_50 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_51;
		L_51 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)21), NULL);
		RuntimeObject* L_52;
		L_52 = MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036(L_50, L_51, MetricsCollectionExtensions_GetEventValues_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m19AC92279B68D88517B45E5AAE1A0A0D6A0A6036_RuntimeMethod_var);
		NullCheck(L_46);
		MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C(L_46, L_49, L_52, MetricCounters_Sample_TisNetworkVariableEvent_tAC73181CA57FA3B7E18557E831648524A1BBC19D_m5EFE5E2111D544D9AE9BC6B90112E341B44D679C_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:92>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:93>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:94>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_53 = __this->___objectSpawned;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_54 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_55;
		L_55 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)26), NULL);
		RuntimeObject* L_56;
		L_56 = MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72(L_54, L_55, MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_57 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_58;
		L_58 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)25), NULL);
		RuntimeObject* L_59;
		L_59 = MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72(L_57, L_58, MetricsCollectionExtensions_GetEventValues_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m275A041D7F3A1E75172B9E1F39EA2304A43E1C72_RuntimeMethod_var);
		NullCheck(L_53);
		MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A(L_53, L_56, L_59, MetricCounters_Sample_TisObjectSpawnedEvent_tFCC2F87A9852BE3CC803D674023828B189B48BBF_m2F2297306D77AD05DE12AE2AD2C643E9178B417A_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:96>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:97>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:98>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_60 = __this->___objectDestroyed;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_61 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_62;
		L_62 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)30), NULL);
		RuntimeObject* L_63;
		L_63 = MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F(L_61, L_62, MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_64 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_65;
		L_65 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)29), NULL);
		RuntimeObject* L_66;
		L_66 = MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F(L_64, L_65, MetricsCollectionExtensions_GetEventValues_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_m0EC8AE9FE40BDB493C598CD41EEF7DB25CE0E08F_RuntimeMethod_var);
		NullCheck(L_60);
		MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0(L_60, L_63, L_66, MetricCounters_Sample_TisObjectDestroyedEvent_t37337CBDE861F8B9EDF6F5ABB4487602C17E53F5_mC47BD2474BD13F6D07C917DDFC4EE67B761F57E0_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:100>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:101>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:102>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_67 = __this->___serverLog;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_68 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_69;
		L_69 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)38), NULL);
		RuntimeObject* L_70;
		L_70 = MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56(L_68, L_69, MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_71 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_72;
		L_72 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)37), NULL);
		RuntimeObject* L_73;
		L_73 = MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56(L_71, L_72, MetricsCollectionExtensions_GetEventValues_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_m238768EC409BF5DE9E12ED660221A6A4A35A1E56_RuntimeMethod_var);
		NullCheck(L_67);
		MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F(L_67, L_70, L_73, MetricCounters_Sample_TisServerLogEvent_tC74D1D7C544E4874605F582EE3D3F9913AEBFDCF_mFBA81E76F01FCEA269277979B1B5135ED7DF2F0F_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:104>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:105>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:106>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_74 = __this->___sceneEvent;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_75 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_76;
		L_76 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)42), NULL);
		RuntimeObject* L_77;
		L_77 = MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196(L_75, L_76, MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_78 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_79;
		L_79 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)41), NULL);
		RuntimeObject* L_80;
		L_80 = MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196(L_78, L_79, MetricsCollectionExtensions_GetEventValues_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_mDFBD78EFF34C30F8B419CD86AE71858EB0D08196_RuntimeMethod_var);
		NullCheck(L_74);
		MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89(L_74, L_77, L_80, MetricCounters_Sample_TisSceneEventMetric_tA698F44A9A76CFD517DAFC17B82BC424973E3D11_m841BD460B09CC5B2C4AB9923D6786C81C3D28A89_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:108>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:109>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:110>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_81 = __this->___ownershipChange;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_82 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_83;
		L_83 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)34), NULL);
		RuntimeObject* L_84;
		L_84 = MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586(L_82, L_83, MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_85 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_86;
		L_86 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)33), NULL);
		RuntimeObject* L_87;
		L_87 = MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586(L_85, L_86, MetricsCollectionExtensions_GetEventValues_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m9B5D95A4E2AC17EE162E6C8EBFC72EE160B9A586_RuntimeMethod_var);
		NullCheck(L_81);
		MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155(L_81, L_84, L_87, MetricCounters_Sample_TisOwnershipChangeEvent_t87B6E5EFF0A89CF29ED5E6A410C4D8562101AD38_m921A8F16EBD161F4148FB4A7F0D7E8CF185F1155_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:112>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:113>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:114>
		MetricCounters_t5EED6DBE4970C6486197333F04361A49608FC5A0* L_88 = __this->___networkMessage;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_89 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_90;
		L_90 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)46), NULL);
		RuntimeObject* L_91;
		L_91 = MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A(L_89, L_90, MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A_RuntimeMethod_var);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_92 = ___0_collection;
		MetricId_t9B12C3D1517436215EA243A319FDFC36F9C4438C L_93;
		L_93 = DirectedMetricTypeExtensions_GetId_m15AA9635645E3422BB8357FFADEB3C4F02AC7836(((int32_t)45), NULL);
		RuntimeObject* L_94;
		L_94 = MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A(L_92, L_93, MetricsCollectionExtensions_GetEventValues_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_mB0BFDC2E03FD0F6A9139F01EF00E2180CB54699A_RuntimeMethod_var);
		NullCheck(L_88);
		MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A(L_88, L_91, L_94, MetricCounters_Sample_TisNetworkMessageEvent_tD3FF4DD5E7E500CCD93C16B4D3877F2C21199E21_m04E027EDB5549EF366C6F88C9156209D212CF01A_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/ProfilerCounters.cs:115>
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144064
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FrameInfo__cctor_m9B13BF4C44239CDAC464AA765ED32865EC413E34 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral881CFDF35EA59A6A902F74DFC7CD5D24039ECC88);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Frame/FrameInfo.cs:7>
		Guid_t L_0;
		memset((&L_0), 0, sizeof(L_0));
		Guid__ctor_mAE66BA1C43B4194F4F7991E2E30370E36CBBF830((&L_0), _stringLiteral881CFDF35EA59A6A902F74DFC7CD5D24039ECC88, NULL);
		((FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_StaticFields*)il2cpp_codegen_static_fields_for(FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_il2cpp_TypeInfo_var))->___NetworkProfilerGuid = L_0;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 144065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener_SubscribeToAdapterAndMetricEvents_mD5C1B513417F2C0D86A7851DE04261960EB523F3 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetworkAdapters_t920951156C811E1CA3946E5BC7885C8D51C9D1E2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_OnAdapterAdded_mE8FFB57D503CDB4FEB9BB80A62C489436689CD71_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_OnAdapterRemoved_m2D96FF92DE1111A3CAB6B07E1852C80C1B03A6BB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:18>
		il2cpp_codegen_runtime_class_init_inline(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		bool L_0 = ((ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var))->___s_Initialized;
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0033;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:20>
		il2cpp_codegen_runtime_class_init_inline(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		((ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var))->___s_Initialized = (bool)1;
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:21>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:22>
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:23>
		Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11* L_2 = (Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11*)il2cpp_codegen_object_new(Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11_il2cpp_TypeInfo_var);
		Action_1__ctor_m3880508FAD3D34B163F6EBF8E1292EDC8BC3BA11(L_2, NULL, (intptr_t)((void*)ProfilerAdapterEventListener_OnAdapterAdded_mE8FFB57D503CDB4FEB9BB80A62C489436689CD71_RuntimeMethod_var), NULL);
		Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11* L_3 = (Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11*)il2cpp_codegen_object_new(Action_1_t8DDBAA92DE7828AE17B1CC89A0C19513FF23DB11_il2cpp_TypeInfo_var);
		Action_1__ctor_m3880508FAD3D34B163F6EBF8E1292EDC8BC3BA11(L_3, NULL, (intptr_t)((void*)ProfilerAdapterEventListener_OnAdapterRemoved_m2D96FF92DE1111A3CAB6B07E1852C80C1B03A6BB_RuntimeMethod_var), NULL);
		il2cpp_codegen_runtime_class_init_inline(NetworkAdapters_t920951156C811E1CA3946E5BC7885C8D51C9D1E2_il2cpp_TypeInfo_var);
		UnsubscribeFromAllAdapters_t2C59AA45D1C66736C7F8B20FD0A85FF292D43CD3* L_4;
		L_4 = NetworkAdapters_SubscribeToAll_m723AC3FD21865EC093EA0E18E00007642790850A(L_2, L_3, NULL);
	}

IL_0033:
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:25>
		return;
	}
}
// Method Definition Index: 144066
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener_OnAdapterAdded_mE8FFB57D503CDB4FEB9BB80A62C489436689CD71 (RuntimeObject* ___0_adapter, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&INetworkAdapter_GetComponent_TisIMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_m7765E89563B9852071A89ABE8C094E3A4155D645_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_OnMetricsReceived_m23E7098C67648C4CC541351C6ADEA74C638C6D97_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	bool V_1 = false;
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:29>
		RuntimeObject* L_0 = ___0_adapter;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = GenericInterfaceFuncInvoker0< RuntimeObject* >::Invoke(INetworkAdapter_GetComponent_TisIMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_m7765E89563B9852071A89ABE8C094E3A4155D645_RuntimeMethod_var, L_0);
		V_0 = L_1;
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:30>
		RuntimeObject* L_2 = V_0;
		V_1 = (bool)((!(((RuntimeObject*)(RuntimeObject*)L_2) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0025;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:32>
		RuntimeObject* L_4 = V_0;
		Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079* L_5 = (Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079*)il2cpp_codegen_object_new(Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079_il2cpp_TypeInfo_var);
		Action_1__ctor_m4F86B44384B4643D150CD9065F7B672056D27145(L_5, NULL, (intptr_t)((void*)ProfilerAdapterEventListener_OnMetricsReceived_m23E7098C67648C4CC541351C6ADEA74C638C6D97_RuntimeMethod_var), NULL);
		NullCheck(L_4);
		InterfaceActionInvoker1< Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079* >::Invoke(0, IMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_il2cpp_TypeInfo_var, L_4, L_5);
	}

IL_0025:
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:34>
		return;
	}
}
// Method Definition Index: 144067
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener_OnAdapterRemoved_m2D96FF92DE1111A3CAB6B07E1852C80C1B03A6BB (RuntimeObject* ___0_adapter, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&INetworkAdapter_GetComponent_TisIMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_m7765E89563B9852071A89ABE8C094E3A4155D645_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_OnMetricsReceived_m23E7098C67648C4CC541351C6ADEA74C638C6D97_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	bool V_1 = false;
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:38>
		RuntimeObject* L_0 = ___0_adapter;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = GenericInterfaceFuncInvoker0< RuntimeObject* >::Invoke(INetworkAdapter_GetComponent_TisIMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_m7765E89563B9852071A89ABE8C094E3A4155D645_RuntimeMethod_var, L_0);
		V_0 = L_1;
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:39>
		RuntimeObject* L_2 = V_0;
		V_1 = (bool)((!(((RuntimeObject*)(RuntimeObject*)L_2) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0025;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:41>
		RuntimeObject* L_4 = V_0;
		Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079* L_5 = (Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079*)il2cpp_codegen_object_new(Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079_il2cpp_TypeInfo_var);
		Action_1__ctor_m4F86B44384B4643D150CD9065F7B672056D27145(L_5, NULL, (intptr_t)((void*)ProfilerAdapterEventListener_OnMetricsReceived_m23E7098C67648C4CC541351C6ADEA74C638C6D97_RuntimeMethod_var), NULL);
		NullCheck(L_4);
		InterfaceActionInvoker1< Action_1_t76E00A62308B4884D5FBE7973531637E07E7B079* >::Invoke(1, IMetricCollectionEvent_tA72E299C92E8C93B12BA2474EB44722BE3EFF258_il2cpp_TypeInfo_var, L_4, L_5);
	}

IL_0025:
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:43>
		return;
	}
}
// Method Definition Index: 144068
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener_OnMetricsReceived_m23E7098C67648C4CC541351C6ADEA74C638C6D97 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_metricCollection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:47>
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_0 = ___0_metricCollection;
		il2cpp_codegen_runtime_class_init_inline(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		ProfilerAdapterEventListener_PopulateProfilerIfEnabled_mA1EE8D6408312BC481F95A8E9E91E17B23EEAA23(L_0, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:48>
		return;
	}
}
// Method Definition Index: 144069
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener_PopulateProfilerIfEnabled_mA1EE8D6408312BC481F95A8E9E91E17B23EEAA23 (MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* ___0_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:55>
		ProfilerCounters_t1C839C38EFDAC44F3D884ADD616F6AF8F23A00C3* L_0;
		L_0 = ProfilerCounters_get_Instance_m55A0FA5692DC4C5C6E0E37A8C247DAE78328383B(NULL);
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_1 = ___0_collection;
		NullCheck(L_0);
		ProfilerCounters_UpdateFromMetrics_mD3171E543D39C1180FD915DF42AD0130628C677E(L_0, L_1, NULL);
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:57>
		il2cpp_codegen_runtime_class_init_inline(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E* L_2 = ((ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var))->___s_NetStatSerializer;
		MetricCollection_tC854AC2B17132ADE592D32683C1EF00AB6B2B8AA* L_3 = ___0_collection;
		NullCheck(L_2);
		NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF L_4;
		L_4 = NetStatSerializer_Serialize_mAD36C6DA9699EFCB8EC8D58CDB44A0BEDD0CD9B3(L_2, L_3, NULL);
		V_0 = L_4;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0028:
			{
				NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA((&V_0), NativeArray_1_Dispose_m8B0F342847ECB90EB814E1F6AA5BF7DC2F271AEA_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:58>
			//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:59>
			//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:60>
			//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:61>
			il2cpp_codegen_runtime_class_init_inline(FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_il2cpp_TypeInfo_var);
			Guid_t L_5 = ((FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_StaticFields*)il2cpp_codegen_static_fields_for(FrameInfo_t143CD9AEDBA9EE19B1D8979BA3A7CF8F524B2F9D_il2cpp_TypeInfo_var))->___NetworkProfilerGuid;
			NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF L_6 = V_0;
			Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7(L_5, 0, L_6, Profiler_EmitFrameMetaData_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m31E829968CED99457E2088C83EC1DEC7284F30E7_RuntimeMethod_var);
			//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:62>
			goto IL_0037;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0037:
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:62>
		return;
	}
}
// Method Definition Index: 144070
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerAdapterEventListener__cctor_m95F9F00DD1794CD7AE0D1578EB785861B798A8C9 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/ProfilerAdapterEventListener.cs:50>
		NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E* L_0 = (NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E*)il2cpp_codegen_object_new(NetStatSerializer_t9F27B48ACF02B224520014E32721BDFE2B25697E_il2cpp_TypeInfo_var);
		NetStatSerializer__ctor_m9C4C58C9E498B39BD958D5596470165CC74318F2(L_0, NULL);
		((ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var))->___s_NetStatSerializer = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_StaticFields*)il2cpp_codegen_static_fields_for(ProfilerAdapterEventListener_t8B16080549E55A9638611877E08003299BA642C3_il2cpp_TypeInfo_var))->___s_NetStatSerializer), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 144048
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricByteCounters_get_Sent_mC97D8190FB75086A6566747A73E5CEA1EECFB4E6_inline (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:20>
		String_t* L_0 = __this->___U3CSentU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144049
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricByteCounters_get_Received_m59C838195C22C352ABA8D7F0AB49FC09ED7E93F2_inline (MetricByteCounters_t93939B32EAFF5C62DEAC49479C24B257BED5AC16* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricByteCounters.cs:22>
		String_t* L_0 = __this->___U3CReceivedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144054
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricEventCounters_get_Sent_m78BE5E723C71AB0CAAF3BBC0F5FDC6DC35871D7F_inline (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:7>
		String_t* L_0 = __this->___U3CSentU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144055
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MetricEventCounters_get_Received_m8B0522797455165C4CA584D2351D008182DF0C42_inline (MetricEventCounters_t6018F3D388A02986183F5884F3D18564D9F6C172* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.multiplayer.tools@a1cbe02da79e/NetworkProfiler/Runtime/Counter/MetricEventCounters.cs:10>
		String_t* L_0 = __this->___U3CReceivedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 144075
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerCounter_1__ctor_m72EFD69FAA82C502E583EA8D3745B0DE476199ED_gshared_inline (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* __this, ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC ___0_category, String_t* ___1_name, uint8_t ___2_dataUnit, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:43>
		uint8_t L_0;
		L_0 = ProfilerUtility_GetProfilerMarkerDataType_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_mFEA9A9D2DBAF423513797DF56A48F9E1B18A9DF2(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 0));
		__this->___m_Type = L_0;
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:44>
		String_t* L_1 = ___1_name;
		ProfilerCategory_tA55212CD512C618AF6D2147791F20319896592AC L_2 = ___0_category;
		uint16_t L_3;
		L_3 = ProfilerCategory_op_Implicit_m441AE38B56781EE2D3F0865F65C81A77BEC6D76B(L_2, NULL);
		intptr_t L_4;
		L_4 = ProfilerUnsafeUtility_CreateMarker_mC5E1AAB8CC1F0342065DF85BA3334445ED754E64(L_1, L_3, (uint16_t)((int32_t)128), 1, NULL);
		__this->___m_Ptr = L_4;
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:45>
		intptr_t L_5 = __this->___m_Ptr;
		uint8_t L_6 = __this->___m_Type;
		uint8_t L_7 = ___2_dataUnit;
		ProfilerUnsafeUtility_SetMarkerMetadata_mD5FD13DE489F9C2E0E7D0AF209CD9369375CFA16(L_5, 0, (String_t*)NULL, L_6, (uint8_t)L_7, NULL);
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:47>
		return;
	}
}
// Method Definition Index: 144076
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerCounter_1_Sample_m20C358BFC346EA9A67033C5E2ECFFCD801EC8779_gshared_inline (ProfilerCounter_1_t164CEA6505C01A0E203C256D3F24F0D943978945* __this, int64_t ___0_value, const RuntimeMethod* method) 
{
	ProfilerMarkerData_tC01B15D61B904B700E4DE1FFB3452F2C5C2789A2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarkerData_tC01B15D61B904B700E4DE1FFB3452F2C5C2789A2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:62>
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:63>
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:64>
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:65>
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:66>
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:67>
		il2cpp_codegen_initobj((&V_1), sizeof(ProfilerMarkerData_tC01B15D61B904B700E4DE1FFB3452F2C5C2789A2));
		uint8_t L_0 = __this->___m_Type;
		(&V_1)->___Type = L_0;
		int32_t L_1;
		L_1 = UnsafeUtility_SizeOf_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m9712F6405A5D5C4128EAFA7860A222DE388ED6C5_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2));
		(&V_1)->___Size = (uint32_t)L_1;
		void* L_2;
		L_2 = il2cpp_codegen_unsafe_cast((&___0_value));
		(&V_1)->___Ptr = L_2;
		ProfilerMarkerData_tC01B15D61B904B700E4DE1FFB3452F2C5C2789A2 L_3 = V_1;
		V_0 = L_3;
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:68>
		intptr_t L_4 = __this->___m_Ptr;
		ProfilerUnsafeUtility_SingleSampleWithMetadata_mA4CD442AA9596086004E36704DCE40F8B5D8AC9A(L_4, 1, (void*)((uintptr_t)(&V_0)), NULL);
		//<source_info:./Library/PackageCache/com.unity.profiling.core@8a49f7027d06/Runtime/ProfilerCounter.cs:71>
		return;
	}
}
// Method Definition Index: 78812
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m9712F6405A5D5C4128EAFA7860A222DE388ED6C5_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int64_t);
		return (int32_t)L_0;
	}
}
