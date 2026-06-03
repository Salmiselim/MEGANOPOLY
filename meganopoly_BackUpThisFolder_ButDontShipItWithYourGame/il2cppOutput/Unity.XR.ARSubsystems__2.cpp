#include "pch-cpp.hpp"





template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

struct Dictionary_2_t5B5B38BB06341F50E1C75FB53208A2A66CAE57F7;
struct WeakReference_1_tDC6E83496181D1BAFA3B89CBC00BCD0B64450257;
struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct GroupU5BU5D_t9924453EAB39E5BC350475A536C5C7093F9A04A9;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct Capture_tE11B735186DAFEE5F7A3BF5A739E9CCCE99DC24A;
struct CaptureCollection_t38405272BD6A6DA77CD51487FD39624C6E95CC93;
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
struct Exception_t;
struct ExclusiveReference_t411F04D4CC440EB7399290027E1BBABEF4C28837;
struct FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B;
struct Group_t26371E9136D6F43782C487B63C67C5FC4F472881;
struct GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E;
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct ITrackable_t8A51BCCE68DE3182CE850CF98949D79C50193F6A;
struct Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F;
struct Regex_tE773142C2BE45C5D362B0F815AFF831707A51772;
struct RegexCode_tA23175D9DA02AD6A79B073E10EC5D225372ED6C7;
struct RegexRunnerFactory_t72373B672C7D8785F63516DDD88834F286AF41E7;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct CachedCodeEntry_tE201C3AD65C234AD9ED7A78C95025824A7A9FF39;

IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnity_XR_ARSubsystems[];
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnity_XR_OpenXR[];
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Regex_tE773142C2BE45C5D362B0F815AFF831707A51772_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral241BE6E385975D9F12D5076DDE1873A5D169C4B4;
IL2CPP_EXTERN_C String_t* _stringLiteral27A34E033C9A6BBBDD443A6D2BC0C16783E281B0;
IL2CPP_EXTERN_C String_t* _stringLiteral42646B33B50B6AA15E22733C8900716F0FE19E1D;
IL2CPP_EXTERN_C String_t* _stringLiteral5856982C295C68DD87C424F2F7B795A142D7C134;
IL2CPP_EXTERN_C String_t* _stringLiteralA56CB75B19CD4AE3099069A8FAE874B97EE80348;
IL2CPP_EXTERN_C String_t* _stringLiteralB9E1CB07B1BC79148DB21D87F48D50AC486D3A55;
IL2CPP_EXTERN_C String_t* _stringLiteralBEC9FDEA1EB953376E5F17E9CEC1AFAC97FDD26D;
IL2CPP_EXTERN_C String_t* _stringLiteralE7BA25708447ADB5ACEB732C9C4C47F88C501037;
IL2CPP_EXTERN_C const RuntimeMethod* ITrackable_get_parentId_m542903626AFBFCD5A44381546CEC0585154235BA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* OpenXRResultStatus_get_nativeStatusCode_m8B3E8230C7ADF5C1F04F1C5A56D07A7C82173691_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* OpenXRResultStatus_get_statusCode_m10FB4D54C67DCA0E3CBE3F99771DE593EE2B5914_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SerializableGuid_get_guidHigh_mA9BBF728882044319A7B9842AB431D8171C9E0D7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SerializableGuid_get_guidLow_m15602EFCE301E6CD42BB1504B6CB30C12723F0BC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId__cctor_m0233247C572757642543FD7F9D7AFFA432EC916F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_get_invalidId_mDAEC47FD9C1E08B9D5752DA8F185E7A783DBE494_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_op_Equality_m9E51E31C58CA710A1BD2E3AE1D2286E2FE5B3529_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_op_Implicit_mD9E1532321EC27C4D92FCB22F2979AFC32220D17_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_op_Inequality_mBEED941F67FCF17377C6F01882CBA551B47246D4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_get_unqualifiedSuccess_mF88DE6F5E8C28E2DF3A76A2D7B575E9CC01F8093_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_op_Explicit_m1117F3ABCFE0C48C4C8515F73198902155611DD0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_op_Implicit_m32BA3B804441C4F7FBDC903F4E3D934F63E11D23_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_op_Implicit_m79BE466B9B264BE8D9727152B9AFE665D473FC74_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRResultStatus_op_Implicit_mCCE12AEFA374B8A50A1493C4C35EAAD854FE0484_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRTextureTypeExtensions_IsRenderTexture_mED6B89BAA0ECB21BABB5452EED0755D14AC42956_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRTextureTypeExtensions_ToTextureDimension_m196396773E26776AB57A2A072C586B97DA518A7E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* XRTextureTypeExtensions_ToXRTextureType_m5AF2A1F9CDE5E7661E7FF0E34D648A7A5193B4BF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* Exception_t_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ITrackable_t8A51BCCE68DE3182CE850CF98949D79C50193F6A_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* XRTextureType_t5591061F923F907341986D46F0322DE15DCB9955_0_0_0_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CPrivateImplementationDetailsU3E_t0459A65C4515C83F051BDB26AD470E21E4410D52  : public RuntimeObject
{
};
struct Capture_tE11B735186DAFEE5F7A3BF5A739E9CCCE99DC24A  : public RuntimeObject
{
	int32_t ___U3CIndexU3Ek__BackingField;
	int32_t ___U3CLengthU3Ek__BackingField;
	String_t* ___U3CTextU3Ek__BackingField;
};
struct GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E  : public RuntimeObject
{
	Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* ____match;
	Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* ____captureMap;
	GroupU5BU5D_t9924453EAB39E5BC350475A536C5C7093F9A04A9* ____groups;
};
struct ObjectPoolCreateUtil_t2347CB1BFE4B0F03D3F445424B809A11B02F6F07  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
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
struct XRTextureTypeExtensions_t298A6D38C57ABF6455D504FD1A4538E0CBF24515  : public RuntimeObject
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
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
struct Group_t26371E9136D6F43782C487B63C67C5FC4F472881  : public Capture_tE11B735186DAFEE5F7A3BF5A739E9CCCE99DC24A
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____caps;
	int32_t ____capcount;
	CaptureCollection_t38405272BD6A6DA77CD51487FD39624C6E95CC93* ____capcoll;
	String_t* ___U3CNameU3Ek__BackingField;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378 
{
	uint64_t ___m_GuidLow;
	uint64_t ___m_GuidHigh;
};
struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A 
{
	int64_t ____ticks;
};
struct TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 
{
	uint64_t ___m_SubId1;
	uint64_t ___m_SubId2;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
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
struct __StaticArrayInitTypeSizeU3D14936_t4AEABA43C7AF59F166CC1AA5C0A040D4ED784E80 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D14936_t4AEABA43C7AF59F166CC1AA5C0A040D4ED784E80__padding[14936];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D9112_tC95758F5C16BE4FACF0F3655DFF1DC59E5ABC516 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D9112_tC95758F5C16BE4FACF0F3655DFF1DC59E5ABC516__padding[9112];
	};
};
#pragma pack(pop, tp)
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F  : public Group_t26371E9136D6F43782C487B63C67C5FC4F472881
{
	GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E* ____groupcoll;
	Regex_tE773142C2BE45C5D362B0F815AFF831707A51772* ____regex;
	int32_t ____textbeg;
	int32_t ____textpos;
	int32_t ____textend;
	int32_t ____textstart;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ____matches;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____matchcount;
	bool ____balancing;
};
struct NumberStyles_t567C6CBC2A2B5B5A2C43B2855D158949984A810C 
{
	int32_t ___value__;
};
struct RegexOptions_tE9DA9C4DF8FB26DD1C7E0F8AA022C1164A423F6B 
{
	int32_t ___value__;
};
struct TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642 
{
	int32_t ___value__;
};
struct TrackingState_t5487241B6888BB15D8448EBBC640835A011DBBC2 
{
	int32_t ___value__;
};
struct XRTextureType_t5591061F923F907341986D46F0322DE15DCB9955 
{
	int32_t ___value__;
};
struct XrResult_tC6E780422C0CF27153FB9B0ED7D1F60015608195 
{
	int32_t ___value__;
};
struct StatusCode_tF7B3103902B2FC08270F132BF7D56DDA6803F10F 
{
	int32_t ___value__;
};
struct StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B 
{
	int32_t ___value__;
};
struct OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1 
{
	int32_t ___U3CstatusCodeU3Ek__BackingField;
	int32_t ___U3CnativeStatusCodeU3Ek__BackingField;
};
struct Regex_tE773142C2BE45C5D362B0F815AFF831707A51772  : public RuntimeObject
{
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___internalMatchTimeout;
	String_t* ___pattern;
	int32_t ___roptions;
	RegexRunnerFactory_t72373B672C7D8785F63516DDD88834F286AF41E7* ___factory;
	Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* ___caps;
	Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* ___capnames;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___capslist;
	int32_t ___capsize;
	ExclusiveReference_t411F04D4CC440EB7399290027E1BBABEF4C28837* ____runnerref;
	WeakReference_1_tDC6E83496181D1BAFA3B89CBC00BCD0B64450257* ____replref;
	RegexCode_tA23175D9DA02AD6A79B073E10EC5D225372ED6C7* ____code;
	bool ____refsInitialized;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 
{
	int32_t ___m_StatusCode;
	int32_t ___m_NativeStatusCode;
};
struct FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct U3CPrivateImplementationDetailsU3E_t0459A65C4515C83F051BDB26AD470E21E4410D52_StaticFields
{
	__StaticArrayInitTypeSizeU3D14936_t4AEABA43C7AF59F166CC1AA5C0A040D4ED784E80 ___230E418DCCC1749D65DE986655C93AD2476A58C627D721E591F2A27881CC2798;
	__StaticArrayInitTypeSizeU3D9112_tC95758F5C16BE4FACF0F3655DFF1DC59E5ABC516 ___B9F12A8B26CD7608C9FB0BB35C9EC5D71F98B7CF55AD825414FB544BDB40CA32;
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
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray;
};
struct Group_t26371E9136D6F43782C487B63C67C5FC4F472881_StaticFields
{
	Group_t26371E9136D6F43782C487B63C67C5FC4F472881* ___s_emptyGroup;
};
struct SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_StaticFields
{
	SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378 ___k_Empty;
};
struct TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_StaticFields
{
	Regex_tE773142C2BE45C5D362B0F815AFF831707A51772* ___s_TrackableIdRegex;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F_StaticFields
{
	Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* ___U3CEmptyU3Ek__BackingField;
};
struct Regex_tE773142C2BE45C5D362B0F815AFF831707A51772_StaticFields
{
	int32_t ___s_cacheSize;
	Dictionary_2_t5B5B38BB06341F50E1C75FB53208A2A66CAE57F7* ___s_cache;
	int32_t ___s_cacheCount;
	CachedCodeEntry_tE201C3AD65C234AD9ED7A78C95025824A7A9FF39* ___s_cacheFirst;
	CachedCodeEntry_tE201C3AD65C234AD9ED7A78C95025824A7A9FF39* ___s_cacheLast;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___s_maximumMatchTimeout;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___s_defaultMatchTimeout;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___InfiniteMatchTimeout;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_subId1, uint64_t ___1_subId2, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* Regex_Match_m58565ECF23ACCD2CA77D6F10A6A182B03CF0FF84 (Regex_tE773142C2BE45C5D362B0F815AFF831707A51772* __this, String_t* ___0_input, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Group_get_Success_m4E0238EE4B1E7F927E2AF13E2E5901BCA92BE62F (Group_t26371E9136D6F43782C487B63C67C5FC4F472881* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FormatException__ctor_mE04AEA59C0EEFF4BD34B7CE8601F9D331D1D473E (FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Group_t26371E9136D6F43782C487B63C67C5FC4F472881* GroupCollection_get_Item_mE9B3A83B3563620EF70CFCD5F13E404864351B7A (GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E* __this, String_t* ___0_groupname, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Capture_get_Value_m1AB4193C2FC4B0D08AA34FECF10D03876D848BDC (Capture_tE11B735186DAFEE5F7A3BF5A739E9CCCE99DC24A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t UInt64_Parse_m5D07DDFA6DA8E3F85D6E07EAE33756AF742CBAB0 (String_t* ___0_s, int32_t ___1_style, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FormatException__ctor_mE31CCFC2A6FA296CA9E9C6813112D7850FE682D4 (FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B* __this, String_t* ___0_message, Exception_t* ___1_innerException, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, String_t* ___0_idString, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t SerializableGuid_get_guidLow_m15602EFCE301E6CD42BB1504B6CB30C12723F0BC_inline (SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t SerializableGuid_get_guidHigh_mA9BBF728882044319A7B9842AB431D8171C9E0D7_inline (SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92 (uint64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashCodeUtil_Combine_m98169BF154323DEFC91DB146CDD3CE7550B6AD36 (int32_t ___0_hash1, int32_t ___1_hash2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Regex__ctor_mE3996C71B04A4A6845745D01C93B1D27423D0621 (Regex_tE773142C2BE45C5D362B0F815AFF831707A51772* __this, String_t* ___0_pattern, int32_t ___1_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 TrackableId_get_invalidId_mDAEC47FD9C1E08B9D5752DA8F185E7A783DBE494 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, int32_t ___0_statusCode, int32_t ___1_nativeStatusCode, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, int32_t ___0_statusCode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, int32_t ___0_nativeStatusCode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, bool ___0_wasSuccessful, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpenXRResultStatus_get_statusCode_m10FB4D54C67DCA0E3CBE3F99771DE593EE2B5914_inline (OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpenXRResultStatus_get_nativeStatusCode_m8B3E8230C7ADF5C1F04F1C5A56D07A7C82173691_inline (OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpenXRResultStatus__ctor_mE4545C2757C37AF9A6963733E9EAC8D2D8CA5B57 (OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1* __this, int32_t ___0_statusCode, int32_t ___1_nativeStatusCode, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586 (int32_t* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Enum_CompareTo_m7857C6F62098FB59C5334577863DD23559CD50B5 (RuntimeObject* __this, RuntimeObject* ___0_target, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_other, const RuntimeMethod* method) ;
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
// Method Definition Index: 133350
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRTextureTypeExtensions_IsRenderTexture_mED6B89BAA0ECB21BABB5452EED0755D14AC42956 (int32_t ___0_textureType, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRTextureTypeExtensions_IsRenderTexture_mED6B89BAA0ECB21BABB5452EED0755D14AC42956_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_textureType));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRTextureTypeExtensions_IsRenderTexture_mED6B89BAA0ECB21BABB5452EED0755D14AC42956_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12076));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12077));
	int32_t G_B5_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12078));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:76>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:77>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:78>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:79>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:80>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12079));
		int32_t L_0 = ___0_textureType;
		if ((((int32_t)L_0) == ((int32_t)4)))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_1 = ___0_textureType;
		if ((((int32_t)L_1) == ((int32_t)5)))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_2 = ___0_textureType;
		if ((((int32_t)L_2) == ((int32_t)6)))
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_3 = ___0_textureType;
		G_B5_0 = ((((int32_t)L_3) == ((int32_t)7))? 1 : 0);
		goto IL_0014;
	}

IL_0013:
	{
		G_B5_0 = 1;
	}

IL_0014:
	{
		V_0 = (bool)G_B5_0;
		goto IL_0017;
	}

IL_0017:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:81>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12080));
		bool L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 133351
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t XRTextureTypeExtensions_ToTextureDimension_m196396773E26776AB57A2A072C586B97DA518A7E (int32_t ___0_textureType, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRTextureTypeExtensions_ToTextureDimension_m196396773E26776AB57A2A072C586B97DA518A7E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRTextureType_t5591061F923F907341986D46F0322DE15DCB9955_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_textureType));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRTextureTypeExtensions_ToTextureDimension_m196396773E26776AB57A2A072C586B97DA518A7E_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12081));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12082));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12083));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:90>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12084));
		int32_t L_0 = ___0_textureType;
		V_1 = L_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12085));
		int32_t L_1 = V_1;
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12086));
		int32_t L_2 = V_0;
		switch (L_2)
		{
			case 0:
			{
				goto IL_002d;
			}
			case 1:
			{
				goto IL_0031;
			}
			case 2:
			{
				goto IL_0035;
			}
			case 3:
			{
				goto IL_0039;
			}
			case 4:
			{
				goto IL_003d;
			}
			case 5:
			{
				goto IL_003d;
			}
			case 6:
			{
				goto IL_003d;
			}
			case 7:
			{
				goto IL_003d;
			}
		}
	}
	{
		goto IL_0041;
	}

IL_002d:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:93>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12087));
		V_2 = 0;
		goto IL_0045;
	}

IL_0031:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:95>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12088));
		V_2 = 2;
		goto IL_0045;
	}

IL_0035:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12089));
		V_2 = 3;
		goto IL_0045;
	}

IL_0039:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:99>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12090));
		V_2 = 4;
		goto IL_0045;
	}

IL_003d:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:104>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12091));
		V_2 = 1;
		goto IL_0045;
	}

IL_0041:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:106>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12092));
		V_2 = (-1);
		goto IL_0045;
	}

IL_0045:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:108>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12093));
		int32_t L_3 = V_2;
		return L_3;
	}
}
// Method Definition Index: 133352
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t XRTextureTypeExtensions_ToXRTextureType_m5AF2A1F9CDE5E7661E7FF0E34D648A7A5193B4BF (int32_t ___0_dimension, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TextureDimension_t8D7148B9168256EE1E9AF91378ABA148888CE642_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRTextureTypeExtensions_ToXRTextureType_m5AF2A1F9CDE5E7661E7FF0E34D648A7A5193B4BF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRTextureType_t5591061F923F907341986D46F0322DE15DCB9955_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dimension));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRTextureTypeExtensions_ToXRTextureType_m5AF2A1F9CDE5E7661E7FF0E34D648A7A5193B4BF_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12094));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12095));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12096));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:123>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12097));
		int32_t L_0 = ___0_dimension;
		V_1 = L_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12098));
		int32_t L_1 = V_1;
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12099));
		int32_t L_2 = V_0;
		switch (L_2)
		{
			case 0:
			{
				goto IL_0021;
			}
			case 1:
			{
				goto IL_0031;
			}
			case 2:
			{
				goto IL_0025;
			}
			case 3:
			{
				goto IL_0029;
			}
			case 4:
			{
				goto IL_002d;
			}
		}
	}
	{
		goto IL_0031;
	}

IL_0021:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:126>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12100));
		V_2 = 0;
		goto IL_0035;
	}

IL_0025:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12101));
		V_2 = 1;
		goto IL_0035;
	}

IL_0029:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:130>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12102));
		V_2 = 2;
		goto IL_0035;
	}

IL_002d:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:132>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12103));
		V_2 = 3;
		goto IL_0035;
	}

IL_0031:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:134>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12104));
		V_2 = (-1);
		goto IL_0035;
	}

IL_0035:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRTextureType.cs:136>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12105));
		int32_t L_3 = V_2;
		return L_3;
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
// Method Definition Index: 133353
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 TrackableId_get_invalidId_mDAEC47FD9C1E08B9D5752DA8F185E7A783DBE494 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_get_invalidId_mDAEC47FD9C1E08B9D5752DA8F185E7A783DBE494_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_get_invalidId_mDAEC47FD9C1E08B9D5752DA8F185E7A783DBE494_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12106));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12107));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:31>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12108));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12109));
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_0;
		memset((&L_0), 0, sizeof(L_0));
		TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5((&L_0), ((int64_t)0), ((int64_t)0), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12109));
		return L_0;
	}
}
// Method Definition Index: 133354
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12110));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12111));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:41>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12112));
		uint64_t L_0 = __this->___m_SubId1;
		return L_0;
	}
}
IL2CPP_EXTERN_C  uint64_t TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	uint64_t _returnValue;
	_returnValue = TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133355
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12113));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12114));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:42>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12115));
		uint64_t L_0 = ___0_value;
		__this->___m_SubId1 = L_0;
		return;
	}
}
IL2CPP_EXTERN_C  void TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_AdjustorThunk (RuntimeObject* __this, uint64_t ___0_value, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_inline(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 133356
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12116));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12117));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:50>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12118));
		uint64_t L_0 = __this->___m_SubId2;
		return L_0;
	}
}
IL2CPP_EXTERN_C  uint64_t TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	uint64_t _returnValue;
	_returnValue = TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133357
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12119));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12120));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:51>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12121));
		uint64_t L_0 = ___0_value;
		__this->___m_SubId2 = L_0;
		return;
	}
}
IL2CPP_EXTERN_C  void TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_AdjustorThunk (RuntimeObject* __this, uint64_t ___0_value, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_inline(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 133358
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_subId1, uint64_t ___1_subId2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_subId1), (&___1_subId2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12122));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12123));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12124));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:61>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12125));
		uint64_t L_0 = ___0_subId1;
		__this->___m_SubId1 = L_0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:62>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12126));
		uint64_t L_1 = ___1_subId2;
		__this->___m_SubId2 = L_1;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:63>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12127));
		return;
	}
}
IL2CPP_EXTERN_C  void TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5_AdjustorThunk (RuntimeObject* __this, uint64_t ___0_subId1, uint64_t ___1_subId2, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5(_thisAdjusted, ___0_subId1, ___1_subId2, method);
}
// Method Definition Index: 133359
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, String_t* ___0_idString, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Exception_t_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral27A34E033C9A6BBBDD443A6D2BC0C16783E281B0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5856982C295C68DD87C424F2F7B795A142D7C134);
		s_Il2CppMethodInitialized = true;
	}
	Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* V_0 = NULL;
	bool V_1 = false;
	Exception_t* V_2 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_idString));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12128));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12129));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12130));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:72>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12131));
		il2cpp_codegen_runtime_class_init_inline(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		Regex_tE773142C2BE45C5D362B0F815AFF831707A51772* L_0 = ((TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_StaticFields*)il2cpp_codegen_static_fields_for(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var))->___s_TrackableIdRegex;
		String_t* L_1 = ___0_idString;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12132));
		NullCheck(L_0);
		Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* L_2;
		L_2 = Regex_Match_m58565ECF23ACCD2CA77D6F10A6A182B03CF0FF84(L_0, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12132));
		V_0 = L_2;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:73>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12133));
		Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* L_3 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12134));
		NullCheck(L_3);
		bool L_4;
		L_4 = Group_get_Success_m4E0238EE4B1E7F927E2AF13E2E5901BCA92BE62F(L_3, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12134));
		V_1 = (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12135));
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_0031;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12136));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:75>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12137));
		String_t* L_6 = ___0_idString;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12138));
		String_t* L_7;
		L_7 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB9E1CB07B1BC79148DB21D87F48D50AC486D3A55)), L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA56CB75B19CD4AE3099069A8FAE874B97EE80348)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12138));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12139));
		FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B* L_8 = (FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B_il2cpp_TypeInfo_var)));
		FormatException__ctor_mE04AEA59C0EEFF4BD34B7CE8601F9D331D1D473E(L_8, L_7, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12139));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_8, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF_RuntimeMethod_var)));
	}

IL_0031:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12140));
	}
	try
	{
		STORE_TRY_ID(methodExecutionContext, 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12141));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:80>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12142));
		Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* L_9 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12143));
		NullCheck(L_9);
		GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E* L_10;
		L_10 = VirtualFuncInvoker0< GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E* >::Invoke(5, L_9);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12143));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12144));
		NullCheck(L_10);
		Group_t26371E9136D6F43782C487B63C67C5FC4F472881* L_11;
		L_11 = GroupCollection_get_Item_mE9B3A83B3563620EF70CFCD5F13E404864351B7A(L_10, _stringLiteral5856982C295C68DD87C424F2F7B795A142D7C134, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12144));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12145));
		NullCheck(L_11);
		String_t* L_12;
		L_12 = Capture_get_Value_m1AB4193C2FC4B0D08AA34FECF10D03876D848BDC(L_11, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12145));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12146));
		uint64_t L_13;
		L_13 = UInt64_Parse_m5D07DDFA6DA8E3F85D6E07EAE33756AF742CBAB0(L_12, ((int32_t)515), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12146));
		__this->___m_SubId1 = L_13;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:81>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12147));
		Match_tFBEBCF225BD8EA17BCE6CE3FE5C1BD8E3074105F* L_14 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12148));
		NullCheck(L_14);
		GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E* L_15;
		L_15 = VirtualFuncInvoker0< GroupCollection_tFFA1789730DD9EA122FBE77DC03BFEDCC3F2945E* >::Invoke(5, L_14);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12148));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12149));
		NullCheck(L_15);
		Group_t26371E9136D6F43782C487B63C67C5FC4F472881* L_16;
		L_16 = GroupCollection_get_Item_mE9B3A83B3563620EF70CFCD5F13E404864351B7A(L_15, _stringLiteral27A34E033C9A6BBBDD443A6D2BC0C16783E281B0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12149));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12150));
		NullCheck(L_16);
		String_t* L_17;
		L_17 = Capture_get_Value_m1AB4193C2FC4B0D08AA34FECF10D03876D848BDC(L_16, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12150));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12151));
		uint64_t L_18;
		L_18 = UInt64_Parse_m5D07DDFA6DA8E3F85D6E07EAE33756AF742CBAB0(L_17, ((int32_t)515), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12151));
		__this->___m_SubId2 = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12152));
		goto IL_0099;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0080;
		}
		throw e;
	}

CATCH_0080:
	{
		STORE_TRY_ID(methodExecutionContext, -1);
		Exception_t* L_19 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:83>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12153));
		V_2 = L_19;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12154));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:85>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12155));
		String_t* L_20 = ___0_idString;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12156));
		String_t* L_21;
		L_21 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral241BE6E385975D9F12D5076DDE1873A5D169C4B4)), L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral42646B33B50B6AA15E22733C8900716F0FE19E1D)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12156));
		Exception_t* L_22 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12157));
		FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B* L_23 = (FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B_il2cpp_TypeInfo_var)));
		FormatException__ctor_mE31CCFC2A6FA296CA9E9C6813112D7850FE682D4(L_23, L_21, L_22, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12157));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_23, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF_RuntimeMethod_var)));
	}

IL_0099:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:87>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12158));
		return;
	}
}
IL2CPP_EXTERN_C  void TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF_AdjustorThunk (RuntimeObject* __this, String_t* ___0_idString, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	TrackableId__ctor_m75F2739A83A25E2B7C34DE87E85187F79A4C86AF(_thisAdjusted, ___0_idString, method);
}
// Method Definition Index: 133360
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 TrackableId_op_Implicit_mD9E1532321EC27C4D92FCB22F2979AFC32220D17 (SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378 ___0_serializableGuid, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_op_Implicit_mD9E1532321EC27C4D92FCB22F2979AFC32220D17_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_serializableGuid));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_op_Implicit_mD9E1532321EC27C4D92FCB22F2979AFC32220D17_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12159));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12160));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12161));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12162));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12163));
		il2cpp_codegen_runtime_class_init_inline(SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_il2cpp_TypeInfo_var);
		uint64_t L_0;
		L_0 = SerializableGuid_get_guidLow_m15602EFCE301E6CD42BB1504B6CB30C12723F0BC_inline((&___0_serializableGuid), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12163));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12164));
		uint64_t L_1;
		L_1 = SerializableGuid_get_guidHigh_mA9BBF728882044319A7B9842AB431D8171C9E0D7_inline((&___0_serializableGuid), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12164));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12165));
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_2;
		memset((&L_2), 0, sizeof(L_2));
		TrackableId__ctor_mB12C56ADDEFA44578A429DDA57A6C78B833B41F5((&L_2), L_0, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12165));
		V_0 = L_2;
		goto IL_0017;
	}

IL_0017:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12166));
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 133361
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE7BA25708447ADB5ACEB732C9C4C47F88C501037);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12167));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12168));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12169));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:105>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12170));
		uint64_t L_0 = __this->___m_SubId1;
		uint64_t L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_defaults.uint64_class, &L_1);
		uint64_t L_3 = __this->___m_SubId2;
		uint64_t L_4 = L_3;
		RuntimeObject* L_5 = Box(il2cpp_defaults.uint64_class, &L_4);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12171));
		String_t* L_6;
		L_6 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralE7BA25708447ADB5ACEB732C9C4C47F88C501037, L_2, L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12171));
		V_0 = L_6;
		goto IL_0024;
	}

IL_0024:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:106>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12172));
		String_t* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C  String_t* TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = TrackableId_ToString_m4BE1AD91726751D994E6FB864B231BE5D7D3F85F(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133362
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12173));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12174));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:112>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12175));
		uint64_t* L_0 = (uint64_t*)(&__this->___m_SubId1);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12176));
		int32_t L_1;
		L_1 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12176));
		uint64_t* L_2 = (uint64_t*)(&__this->___m_SubId2);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12177));
		int32_t L_3;
		L_3 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_2, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12177));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12178));
		int32_t L_4;
		L_4 = HashCodeUtil_Combine_m98169BF154323DEFC91DB146CDD3CE7550B6AD36(L_1, L_3, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12178));
		return L_4;
	}
}
IL2CPP_EXTERN_C  int32_t TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = TrackableId_GetHashCode_m6150BF091C3C17A84021CC18B443D5C297F89537(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133363
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_obj));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12179));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12180));
	int32_t G_B3_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:120>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12181));
		RuntimeObject* L_0 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var)))
		{
			goto IL_0016;
		}
	}
	{
		RuntimeObject* L_1 = ___0_obj;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12182));
		il2cpp_codegen_runtime_class_init_inline(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E(__this, ((*(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*)UnBox(L_1, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var))), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12182));
		G_B3_0 = ((int32_t)(L_2));
		goto IL_0017;
	}

IL_0016:
	{
		G_B3_0 = 0;
	}

IL_0017:
	{
		return (bool)G_B3_0;
	}
}
IL2CPP_EXTERN_C  bool TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	bool _returnValue;
	_returnValue = TrackableId_Equals_m67C98169A04DB96CCEBC08A05B3FF9544B52C3E5(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 133364
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_other));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12183));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12184));
	int32_t G_B3_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:127>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12185));
		uint64_t L_0 = __this->___m_SubId1;
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_1 = ___0_other;
		uint64_t L_2 = L_1.___m_SubId1;
		if ((!(((uint64_t)L_0) == ((uint64_t)L_2))))
		{
			goto IL_001e;
		}
	}
	{
		uint64_t L_3 = __this->___m_SubId2;
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_4 = ___0_other;
		uint64_t L_5 = L_4.___m_SubId2;
		G_B3_0 = ((((int64_t)L_3) == ((int64_t)L_5))? 1 : 0);
		goto IL_001f;
	}

IL_001e:
	{
		G_B3_0 = 0;
	}

IL_001f:
	{
		return (bool)G_B3_0;
	}
}
IL2CPP_EXTERN_C  bool TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E_AdjustorThunk (RuntimeObject* __this, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___0_other, const RuntimeMethod* method)
{
	TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7*>(__this + _offset);
	bool _returnValue;
	_returnValue = TrackableId_Equals_m7263BB158392C4F1B57BEE16D4F1FBBCF01E4A6E(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// Method Definition Index: 133365
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TrackableId_op_Equality_m9E51E31C58CA710A1BD2E3AE1D2286E2FE5B3529 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___0_lhs, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___1_rhs, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_op_Equality_m9E51E31C58CA710A1BD2E3AE1D2286E2FE5B3529_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_lhs), (&___1_rhs));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_op_Equality_m9E51E31C58CA710A1BD2E3AE1D2286E2FE5B3529_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12186));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12187));
	int32_t G_B3_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:136>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:137>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12188));
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_0 = ___0_lhs;
		uint64_t L_1 = L_0.___m_SubId1;
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_2 = ___1_rhs;
		uint64_t L_3 = L_2.___m_SubId1;
		if ((!(((uint64_t)L_1) == ((uint64_t)L_3))))
		{
			goto IL_001e;
		}
	}
	{
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_4 = ___0_lhs;
		uint64_t L_5 = L_4.___m_SubId2;
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_6 = ___1_rhs;
		uint64_t L_7 = L_6.___m_SubId2;
		G_B3_0 = ((((int64_t)L_5) == ((int64_t)L_7))? 1 : 0);
		goto IL_001f;
	}

IL_001e:
	{
		G_B3_0 = 0;
	}

IL_001f:
	{
		return (bool)G_B3_0;
	}
}
// Method Definition Index: 133366
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TrackableId_op_Inequality_mBEED941F67FCF17377C6F01882CBA551B47246D4 (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___0_lhs, TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ___1_rhs, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_op_Inequality_mBEED941F67FCF17377C6F01882CBA551B47246D4_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_lhs), (&___1_rhs));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_op_Inequality_mBEED941F67FCF17377C6F01882CBA551B47246D4_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12189));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12190));
	int32_t G_B3_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:146>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:147>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12191));
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_0 = ___0_lhs;
		uint64_t L_1 = L_0.___m_SubId1;
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_2 = ___1_rhs;
		uint64_t L_3 = L_2.___m_SubId1;
		if ((!(((uint64_t)L_1) == ((uint64_t)L_3))))
		{
			goto IL_0021;
		}
	}
	{
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_4 = ___0_lhs;
		uint64_t L_5 = L_4.___m_SubId2;
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_6 = ___1_rhs;
		uint64_t L_7 = L_6.___m_SubId2;
		G_B3_0 = ((((int32_t)((((int64_t)L_5) == ((int64_t)L_7))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_0022;
	}

IL_0021:
	{
		G_B3_0 = 1;
	}

IL_0022:
	{
		return (bool)G_B3_0;
	}
}
// Method Definition Index: 133367
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackableId__cctor_m0233247C572757642543FD7F9D7AFFA432EC916F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Regex_tE773142C2BE45C5D362B0F815AFF831707A51772_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId__cctor_m0233247C572757642543FD7F9D7AFFA432EC916F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBEC9FDEA1EB953376E5F17E9CEC1AFAC97FDD26D);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId__cctor_m0233247C572757642543FD7F9D7AFFA432EC916F_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12192));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12193));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:24>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:25>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:26>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12194));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12195));
		Regex_tE773142C2BE45C5D362B0F815AFF831707A51772* L_0 = (Regex_tE773142C2BE45C5D362B0F815AFF831707A51772*)il2cpp_codegen_object_new(Regex_tE773142C2BE45C5D362B0F815AFF831707A51772_il2cpp_TypeInfo_var);
		Regex__ctor_mE3996C71B04A4A6845745D01C93B1D27423D0621(L_0, _stringLiteralBEC9FDEA1EB953376E5F17E9CEC1AFAC97FDD26D, ((int32_t)540), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12195));
		((TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_StaticFields*)il2cpp_codegen_static_fields_for(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var))->___s_TrackableIdRegex = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_StaticFields*)il2cpp_codegen_static_fields_for(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var))->___s_TrackableIdRegex), (void*)L_0);
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
// Method Definition Index: 133372
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 ITrackable_get_parentId_m542903626AFBFCD5A44381546CEC0585154235BA (RuntimeObject* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITrackable_get_parentId_m542903626AFBFCD5A44381546CEC0585154235BA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITrackable_t8A51BCCE68DE3182CE850CF98949D79C50193F6A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, ITrackable_get_parentId_m542903626AFBFCD5A44381546CEC0585154235BA_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12196));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12197));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackingSubsystem/ITrackable.cs:55>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12198));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12199));
		il2cpp_codegen_runtime_class_init_inline(TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_il2cpp_TypeInfo_var);
		TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7 L_0;
		L_0 = TrackableId_get_invalidId_mDAEC47FD9C1E08B9D5752DA8F185E7A783DBE494(NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12199));
		return L_0;
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
// Method Definition Index: 133403
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 XRResultStatus_get_unqualifiedSuccess_mF88DE6F5E8C28E2DF3A76A2D7B575E9CC01F8093 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_get_unqualifiedSuccess_mF88DE6F5E8C28E2DF3A76A2D7B575E9CC01F8093_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_get_unqualifiedSuccess_mF88DE6F5E8C28E2DF3A76A2D7B575E9CC01F8093_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12519));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12520));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:101>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12521));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12522));
		XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 L_0;
		memset((&L_0), 0, sizeof(L_0));
		XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1((&L_0), 0, 0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12522));
		return L_0;
	}
}
// Method Definition Index: 133404
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12523));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12524));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:107>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12525));
		int32_t L_0 = __this->___m_StatusCode;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133405
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12526));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12527));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:118>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12528));
		int32_t L_0 = __this->___m_NativeStatusCode;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133406
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, int32_t ___0_statusCode, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_statusCode));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12529));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12530));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12531));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12532));
		int32_t L_0 = ___0_statusCode;
		__this->___m_StatusCode = L_0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:129>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12533));
		__this->___m_NativeStatusCode = 0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:130>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12534));
		return;
	}
}
IL2CPP_EXTERN_C  void XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8_AdjustorThunk (RuntimeObject* __this, int32_t ___0_statusCode, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	XRResultStatus__ctor_m975A0ECD0F8CD81851F734A4421021FA780715A8(_thisAdjusted, ___0_statusCode, method);
}
// Method Definition Index: 133407
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, int32_t ___0_nativeStatusCode, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_nativeStatusCode));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12535));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12536));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12537));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:170>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12538));
		int32_t L_0 = ___0_nativeStatusCode;
		__this->___m_NativeStatusCode = L_0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:171>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:172>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:173>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:174>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:175>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:176>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12539));
		if (1)
		{
			goto IL_000c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12540));
	}

IL_000c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12541));
		int32_t L_1 = ___0_nativeStatusCode;
		if ((((int32_t)L_1) > ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_2 = ___0_nativeStatusCode;
		if (!L_2)
		{
			goto IL_0019;
		}
	}
	{
		goto IL_001d;
	}

IL_0015:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:173>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12542));
		V_0 = 1;
		goto IL_0021;
	}

IL_0019:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:174>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12543));
		V_0 = 0;
		goto IL_0021;
	}

IL_001d:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:175>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12544));
		V_0 = (-1);
		goto IL_0021;
	}

IL_0021:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12545));
		if (1)
		{
			goto IL_0025;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12546));
	}

IL_0025:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12547));
		int32_t L_3 = V_0;
		__this->___m_StatusCode = L_3;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:177>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12548));
		return;
	}
}
IL2CPP_EXTERN_C  void XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E_AdjustorThunk (RuntimeObject* __this, int32_t ___0_nativeStatusCode, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	XRResultStatus__ctor_m3BD9DE4A1AF908DA587BBDB67585B29B843C802E(_thisAdjusted, ___0_nativeStatusCode, method);
}
// Method Definition Index: 133408
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, int32_t ___0_statusCode, int32_t ___1_nativeStatusCode, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_statusCode), (&___1_nativeStatusCode));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12549));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12550));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12551));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:186>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12552));
		int32_t L_0 = ___0_statusCode;
		__this->___m_StatusCode = L_0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:187>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12553));
		int32_t L_1 = ___1_nativeStatusCode;
		__this->___m_NativeStatusCode = L_1;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:188>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12554));
		return;
	}
}
IL2CPP_EXTERN_C  void XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1_AdjustorThunk (RuntimeObject* __this, int32_t ___0_statusCode, int32_t ___1_nativeStatusCode, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1(_thisAdjusted, ___0_statusCode, ___1_nativeStatusCode, method);
}
// Method Definition Index: 133409
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, bool ___0_wasSuccessful, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_wasSuccessful));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12555));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12556));
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* G_B2_0 = NULL;
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* G_B3_1 = NULL;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12557));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:199>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12558));
		bool L_0 = ___0_wasSuccessful;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0009;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = ((int32_t)-2);
		G_B3_1 = G_B1_0;
		goto IL_000a;
	}

IL_0009:
	{
		G_B3_0 = 0;
		G_B3_1 = G_B2_0;
	}

IL_000a:
	{
		G_B3_1->___m_StatusCode = G_B3_0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:200>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12559));
		__this->___m_NativeStatusCode = 0;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:201>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12560));
		return;
	}
}
IL2CPP_EXTERN_C  void XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54_AdjustorThunk (RuntimeObject* __this, bool ___0_wasSuccessful, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54(_thisAdjusted, ___0_wasSuccessful, method);
}
// Method Definition Index: 133410
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12561));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12562));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:208>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12563));
		int32_t L_0 = __this->___m_StatusCode;
		return (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	bool _returnValue;
	_returnValue = XRResultStatus_IsUnqualifiedSuccess_mCF513D9D91BA112297B80086FE7F8BFDF23C3533(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133411
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12564));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12565));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:218>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12566));
		int32_t L_0 = __this->___m_StatusCode;
		return (bool)((((int32_t)((((int32_t)L_0) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	bool _returnValue;
	_returnValue = XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133412
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12567));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12568));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:227>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12569));
		int32_t L_0 = __this->___m_StatusCode;
		return (bool)((((int32_t)L_0) < ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	bool _returnValue;
	_returnValue = XRResultStatus_IsError_m6C0D2364D12EC6616288E7CFD60A9537C58D6FE8(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133413
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 XRResultStatus_op_Implicit_m32BA3B804441C4F7FBDC903F4E3D934F63E11D23 (bool ___0_wasSuccessful, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_op_Implicit_m32BA3B804441C4F7FBDC903F4E3D934F63E11D23_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 V_0;
	memset((&V_0), 0, sizeof(V_0));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_wasSuccessful));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_op_Implicit_m32BA3B804441C4F7FBDC903F4E3D934F63E11D23_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12570));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12571));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12572));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12573));
		bool L_0 = ___0_wasSuccessful;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12574));
		XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 L_1;
		memset((&L_1), 0, sizeof(L_1));
		XRResultStatus__ctor_mCC2BBF9A244BBB1CE5B45B68947F66685CE6CD54((&L_1), L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12574));
		V_0 = L_1;
		goto IL_000a;
	}

IL_000a:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:237>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12575));
		XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 133414
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_op_Implicit_mCCE12AEFA374B8A50A1493C4C35EAAD854FE0484 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_status, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_op_Implicit_mCCE12AEFA374B8A50A1493C4C35EAAD854FE0484_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_status));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_op_Implicit_mCCE12AEFA374B8A50A1493C4C35EAAD854FE0484_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12576));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12577));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12578));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:246>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12579));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12580));
		bool L_0;
		L_0 = XRResultStatus_IsSuccess_m85AEB334B3BE189C80E9A7111E469DF1A8EB9599((&___0_status), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12580));
		V_0 = L_0;
		goto IL_000b;
	}

IL_000b:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:247>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12581));
		bool L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 133415
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 XRResultStatus_op_Implicit_m79BE466B9B264BE8D9727152B9AFE665D473FC74 (OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1 ___0_oxrResultStatus, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_op_Implicit_m79BE466B9B264BE8D9727152B9AFE665D473FC74_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 V_0;
	memset((&V_0), 0, sizeof(V_0));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oxrResultStatus));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_op_Implicit_m79BE466B9B264BE8D9727152B9AFE665D473FC74_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12582));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12583));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12584));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:257>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12585));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12586));
		int32_t L_0;
		L_0 = OpenXRResultStatus_get_statusCode_m10FB4D54C67DCA0E3CBE3F99771DE593EE2B5914_inline((&___0_oxrResultStatus), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12586));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12587));
		int32_t L_1;
		L_1 = OpenXRResultStatus_get_nativeStatusCode_m8B3E8230C7ADF5C1F04F1C5A56D07A7C82173691_inline((&___0_oxrResultStatus), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12587));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12588));
		XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 L_2;
		memset((&L_2), 0, sizeof(L_2));
		XRResultStatus__ctor_m3F10EC3945CEAA4D3C283264A28B37A280148BF1((&L_2), L_0, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12588));
		V_0 = L_2;
		goto IL_0017;
	}

IL_0017:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:258>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12589));
		XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 133416
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1 XRResultStatus_op_Explicit_m1117F3ABCFE0C48C4C8515F73198902155611DD0 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_status, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_op_Explicit_m1117F3ABCFE0C48C4C8515F73198902155611DD0_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_status));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_op_Explicit_m1117F3ABCFE0C48C4C8515F73198902155611DD0_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12590));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12591));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12592));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:273>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:274>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12593));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12594));
		int32_t L_0;
		L_0 = XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline((&___0_status), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12594));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12595));
		int32_t L_1;
		L_1 = XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline((&___0_status), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12595));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12596));
		OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1 L_2;
		memset((&L_2), 0, sizeof(L_2));
		OpenXRResultStatus__ctor_mE4545C2757C37AF9A6963733E9EAC8D2D8CA5B57((&L_2), L_0, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12596));
		V_0 = L_2;
		goto IL_0017;
	}

IL_0017:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:275>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12597));
		OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1 L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 133417
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046 (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_other));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12598));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12599));
	int32_t G_B3_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12600));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:286>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12601));
		int32_t L_0 = __this->___m_StatusCode;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12602));
		int32_t L_1;
		L_1 = XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline((&___0_other), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12602));
		if ((!(((uint32_t)L_0) == ((uint32_t)L_1))))
		{
			goto IL_0021;
		}
	}
	{
		int32_t L_2 = __this->___m_NativeStatusCode;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12603));
		int32_t L_3;
		L_3 = XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline((&___0_other), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12603));
		G_B3_0 = ((((int32_t)L_2) == ((int32_t)L_3))? 1 : 0);
		goto IL_0022;
	}

IL_0021:
	{
		G_B3_0 = 0;
	}

IL_0022:
	{
		V_0 = (bool)G_B3_0;
		goto IL_0025;
	}

IL_0025:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:287>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12604));
		bool L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C  bool XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046_AdjustorThunk (RuntimeObject* __this, XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_other, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	bool _returnValue;
	_returnValue = XRResultStatus_Equals_m672E47E91B4DCE70AFEC1A06BE73F04903F35046(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// Method Definition Index: 133418
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_other));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12605));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12606));
	int32_t G_B3_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12607));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:321>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12608));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12609));
		int32_t L_0;
		L_0 = XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12609));
		V_1 = L_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12610));
		int32_t L_1;
		L_1 = XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline((&___0_other), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12610));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12611));
		int32_t L_2;
		L_2 = Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586((&V_1), L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12611));
		V_0 = L_2;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:322>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12612));
		int32_t L_3 = V_0;
		if (!L_3)
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_4 = V_0;
		G_B3_0 = L_4;
		goto IL_003d;
	}

IL_001d:
	{
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12613));
		int32_t L_5;
		L_5 = XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12613));
		V_2 = L_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12614));
		int32_t L_6;
		L_6 = XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline((&___0_other), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12614));
		int32_t L_7 = L_6;
		RuntimeObject* L_8 = Box(StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_il2cpp_TypeInfo_var, &L_7);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12615));
		Il2CppFakeBox<int32_t> L_9(StatusCode_tB2BCF980A5E9E723CE4E05146B7F9CC89EB5BF4B_il2cpp_TypeInfo_var, (&V_2));
		int32_t L_10;
		L_10 = Enum_CompareTo_m7857C6F62098FB59C5334577863DD23559CD50B5((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_9), L_8, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12615));
		G_B3_0 = L_10;
	}

IL_003d:
	{
		V_3 = G_B3_0;
		goto IL_0040;
	}

IL_0040:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12616));
		int32_t L_11 = V_3;
		return L_11;
	}
}
IL2CPP_EXTERN_C  int32_t XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B_AdjustorThunk (RuntimeObject* __this, XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941 ___0_other, const RuntimeMethod* method)
{
	XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = XRResultStatus_CompareTo_m34CEC2F837BD5510CE7BCE285CCAF7C42AD8B64B(_thisAdjusted, ___0_other, method);
	return _returnValue;
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
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 133354
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_get_subId1_m1F4296FEADE76DF0379F20BCBD94E807E2EF021F_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12110));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12111));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:41>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12112));
		uint64_t L_0 = __this->___m_SubId1;
		return L_0;
	}
}
// Method Definition Index: 133355
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_set_subId1_mFA12049C24961BC2FE7D41A2D0FE30DF4B3F39D2_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12113));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12114));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:42>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12115));
		uint64_t L_0 = ___0_value;
		__this->___m_SubId1 = L_0;
		return;
	}
}
// Method Definition Index: 133356
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_get_subId2_m53BAB4D373B736E473381B24CB608EEF666BA24E_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12116));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12117));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:50>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12118));
		uint64_t L_0 = __this->___m_SubId2;
		return L_0;
	}
}
// Method Definition Index: 133357
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_inline (TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackableId_t49EAE8AA4B9584E314518723DC22B66496D47AD7_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, TrackableId_set_subId2_mB7AA91412C0731CF59A8CC24CF75012D3C77C76D_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12119));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12120));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/TrackableId.cs:51>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12121));
		uint64_t L_0 = ___0_value;
		__this->___m_SubId2 = L_0;
		return;
	}
}
// Method Definition Index: 133091
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t SerializableGuid_get_guidLow_m15602EFCE301E6CD42BB1504B6CB30C12723F0BC_inline (SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SerializableGuid_get_guidLow_m15602EFCE301E6CD42BB1504B6CB30C12723F0BC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SerializableGuid_get_guidLow_m15602EFCE301E6CD42BB1504B6CB30C12723F0BC_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 10317));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 10318));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/SerializableGuid.cs:17>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 10319));
		uint64_t L_0 = __this->___m_GuidLow;
		return L_0;
	}
}
// Method Definition Index: 133092
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t SerializableGuid_get_guidHigh_mA9BBF728882044319A7B9842AB431D8171C9E0D7_inline (SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SerializableGuid_get_guidHigh_mA9BBF728882044319A7B9842AB431D8171C9E0D7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SerializableGuid_tCEABDCED6CD954AC100159BDEFC5D414049C0378_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SerializableGuid_get_guidHigh_mA9BBF728882044319A7B9842AB431D8171C9E0D7_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 10320));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 10321));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/SerializableGuid.cs:22>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 10322));
		uint64_t L_0 = __this->___m_GuidHigh;
		return L_0;
	}
}
// Method Definition Index: 133404
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_inline (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_get_statusCode_m2E3CD927B0CCE57E915A7CC4EE384EB84B44D1AA_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12523));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12524));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:107>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12525));
		int32_t L_0 = __this->___m_StatusCode;
		return L_0;
	}
}
// Method Definition Index: 133405
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_inline (XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XRResultStatus_tCC9883C2EC8AE64CE75A3B0BD56DEFB134CEC941_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, XRResultStatus_get_nativeStatusCode_m58E220BF58FFB6EAEDF2D30F00803726FC23F948_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12526));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12527));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/XRResultStatus.cs:118>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 12528));
		int32_t L_0 = __this->___m_NativeStatusCode;
		return L_0;
	}
}
// Method Definition Index: 122895
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpenXRResultStatus_get_statusCode_m10FB4D54C67DCA0E3CBE3F99771DE593EE2B5914_inline (OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpenXRResultStatus_get_statusCode_m10FB4D54C67DCA0E3CBE3F99771DE593EE2B5914_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, OpenXRResultStatus_get_statusCode_m10FB4D54C67DCA0E3CBE3F99771DE593EE2B5914_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_OpenXR + 2657));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_OpenXR + 2658));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.openxr@ef0033a586bf/Runtime/NativeTypes/OpenXRResultStatus.cs:109>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_OpenXR + 2659));
		int32_t L_0 = __this->___U3CstatusCodeU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 122896
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpenXRResultStatus_get_nativeStatusCode_m8B3E8230C7ADF5C1F04F1C5A56D07A7C82173691_inline (OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpenXRResultStatus_get_nativeStatusCode_m8B3E8230C7ADF5C1F04F1C5A56D07A7C82173691_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpenXRResultStatus_tFEAA2E5622D9E0DFC059BCE02302C8A5F9564AF1_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, OpenXRResultStatus_get_nativeStatusCode_m8B3E8230C7ADF5C1F04F1C5A56D07A7C82173691_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_OpenXR + 2660));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_OpenXR + 2661));
	{
		//<source_info:./Library/PackageCache/com.unity.xr.openxr@ef0033a586bf/Runtime/NativeTypes/OpenXRResultStatus.cs:116>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_OpenXR + 2662));
		int32_t L_0 = __this->___U3CnativeStatusCodeU3Ek__BackingField;
		return L_0;
	}
}
