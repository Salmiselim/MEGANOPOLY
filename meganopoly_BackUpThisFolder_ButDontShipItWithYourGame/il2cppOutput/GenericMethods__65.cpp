#include "pch-cpp.hpp"





template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker;
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2Invoker<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1* p1, T2* p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		R ret;
		void* params[2] = { p1, p2 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2, typename T3>
struct VirtualFuncInvoker3
{
	typedef R (*Func)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3* p3)
	{
		void* params[3] = { p1, &p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4;
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4<R, T1, T2, T3*, T4>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2 p2, T3* p3, T4 p4)
	{
		R ret;
		void* params[4] = { &p1, &p2, p3, &p4 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1>
struct ConstrainedFuncInvoker1;
template <typename R, typename T1>
struct ConstrainedFuncInvoker1<R, T1*>
{
	static inline R Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, params, &ret);
		return ret;
	}
};

struct Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30;
struct Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563;
struct Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B;
struct Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98;
struct Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985;
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8;
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B;
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B;
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70;
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9;
struct ITypeConstructor_1_t61D5D3D9EDD28391B0FE316A5641A34D7FF16FD0;
struct ITypeConstructor_1_t5B814DBA70C191660AF27E38032998417073D7A2;
struct ITypeConstructor_1_t63AA3F84ED218C4C0589371B74758F62E3EFCF85;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct ConnectionId_tEA78CDC27F3C855E62B4A8046ECAFF5DB06128EB;
struct ConnectionToken_tC4332AD93CD9451E95FE2AD7805E547B2A2A9F52;
struct EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8;
struct FixedString64Bytes_t0F1B6FFAFD8C15898CD77D91A79AB36AA078E0A5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF;
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C;
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2;
struct UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct ITypeConstructor_tAEA6BC4B87F0F3739E4457F21908EF55F666EB08;
struct TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F;
struct Api_tAE210A8378E537AFD1FA4B99562229CE842377FB;

IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnityEngine_CoreModule[];
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnityEngine_PropertiesModule[];
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnity_Burst[];
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnity_Collections[];
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnity_XR_ARSubsystems[];
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral3E9DC9108B87A8D625803B99E31E1FF1628D278D;
IL2CPP_EXTERN_C String_t* _stringLiteral8753E91E57F4AF26C69DF5B5A006924AF1E9F9C2;
IL2CPP_EXTERN_C const RuntimeMethod* Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ByteU2A_t7A03686A8034AF92EF1EA2D09B280EF590D1174D_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* NativeArray_1_t6E2931CC2E1AA6B9F666FF4270BD177E2114779B_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30  : public RuntimeObject
{
};
struct Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563  : public RuntimeObject
{
};
struct Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B  : public RuntimeObject
{
};
struct Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98  : public RuntimeObject
{
};
struct Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985  : public RuntimeObject
{
};
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8  : public RuntimeObject
{
};
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B  : public RuntimeObject
{
};
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B  : public RuntimeObject
{
};
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70  : public RuntimeObject
{
};
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct SubsystemProvider_tE1865B8FE698C81A59AED35E0E536BD53F402455  : public RuntimeObject
{
	bool ___m_Running;
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
struct TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F  : public RuntimeObject
{
	RuntimeObject* ___TypeConstructor;
};
struct Avx2_tEF5390382630DE33677921890832DA46CE372FBC  : public RuntimeObject
{
};
struct Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C  : public RuntimeObject
{
};
struct Api_tAE210A8378E537AFD1FA4B99562229CE842377FB  : public RuntimeObject
{
};
struct SubsystemProvider_1_t7F23470F737E4D41A109340894B9E2BB7F170781  : public SubsystemProvider_tE1865B8FE698C81A59AED35E0E536BD53F402455
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
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
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
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
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
struct RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 
{
	int32_t ___m_XMin;
	int32_t ___m_YMin;
	int32_t ___m_Width;
	int32_t ___m_Height;
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct UIntPtr_t 
{
	void* ____pointer;
};
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t* ___values;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t* ___values_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keys_OffsetPadding[8];
			uint8_t* ___keys;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keys_OffsetPadding_forAlignmentOnly[8];
			uint8_t* ___keys_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___next_OffsetPadding[16];
			uint8_t* ___next;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___next_OffsetPadding_forAlignmentOnly[16];
			uint8_t* ___next_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___buckets_OffsetPadding[24];
			uint8_t* ___buckets;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___buckets_OffsetPadding_forAlignmentOnly[24];
			uint8_t* ___buckets_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keyCapacity_OffsetPadding[32];
			int32_t ___keyCapacity;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keyCapacity_OffsetPadding_forAlignmentOnly[32];
			int32_t ___keyCapacity_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding[36];
			int32_t ___bucketCapacityMask;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding_forAlignmentOnly[36];
			int32_t ___bucketCapacityMask_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding[40];
			int32_t ___allocatedIndexLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding_forAlignmentOnly[40];
			int32_t ___allocatedIndexLength_forAlignmentOnly;
		};
	};
};
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C 
{
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___m_NextBlock;
	int32_t ___m_NumItems;
};
struct Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A 
{
	int32_t ___m_X;
	int32_t ___m_Y;
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
struct v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___Byte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___Byte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte1_OffsetPadding[1];
			uint8_t ___Byte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___Byte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte2_OffsetPadding[2];
			uint8_t ___Byte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___Byte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte3_OffsetPadding[3];
			uint8_t ___Byte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___Byte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte4_OffsetPadding[4];
			uint8_t ___Byte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___Byte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte5_OffsetPadding[5];
			uint8_t ___Byte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___Byte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte6_OffsetPadding[6];
			uint8_t ___Byte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___Byte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte7_OffsetPadding[7];
			uint8_t ___Byte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___Byte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___SByte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___SByte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte1_OffsetPadding[1];
			int8_t ___SByte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___SByte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte2_OffsetPadding[2];
			int8_t ___SByte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___SByte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte3_OffsetPadding[3];
			int8_t ___SByte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___SByte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte4_OffsetPadding[4];
			int8_t ___SByte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___SByte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte5_OffsetPadding[5];
			int8_t ___SByte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___SByte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte6_OffsetPadding[6];
			int8_t ___SByte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___SByte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte7_OffsetPadding[7];
			int8_t ___SByte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___SByte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___UShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___UShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort1_OffsetPadding[2];
			uint16_t ___UShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___UShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort2_OffsetPadding[4];
			uint16_t ___UShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___UShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort3_OffsetPadding[6];
			uint16_t ___UShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___UShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___SShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___SShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort1_OffsetPadding[2];
			int16_t ___SShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___SShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort2_OffsetPadding[4];
			int16_t ___SShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___SShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort3_OffsetPadding[6];
			int16_t ___SShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___SShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___UInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___UInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt1_OffsetPadding[4];
			uint32_t ___UInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___UInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___SInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___SInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt1_OffsetPadding[4];
			int32_t ___SInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___SInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___ULong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___ULong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___SLong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___SLong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___Float0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___Float0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float1_OffsetPadding[4];
			float ___Float1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float1_OffsetPadding_forAlignmentOnly[4];
			float ___Float1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___Double0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___Double0_forAlignmentOnly;
		};
	};
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 
{
	int64_t ___m_long;
};
struct Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6 
{
	uint8_t* ___Ptr;
	int32_t ___Size;
	int32_t ___Offset;
};
struct U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116 
{
	union
	{
		struct
		{
			uint8_t ___FixedElementField;
		};
		uint8_t U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116__padding[1];
	};
};
struct Array_t3B8F006A80A48C83471DE3516556F1AFE6873381 
{
	union
	{
		struct
		{
		};
		uint8_t Array_t3B8F006A80A48C83471DE3516556F1AFE6873381__padding[1];
	};
};
struct StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___Acc;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___Acc_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Buffer_OffsetPadding[64];
			uint8_t ___Buffer;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Buffer_OffsetPadding_forAlignmentOnly[64];
			uint8_t ___Buffer_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___IsHash64_OffsetPadding[320];
			int32_t ___IsHash64;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___IsHash64_OffsetPadding_forAlignmentOnly[320];
			int32_t ___IsHash64_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___BufferedSize_OffsetPadding[324];
			int32_t ___BufferedSize;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___BufferedSize_OffsetPadding_forAlignmentOnly[324];
			int32_t ___BufferedSize_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___NbStripesSoFar_OffsetPadding[328];
			int32_t ___NbStripesSoFar;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___NbStripesSoFar_OffsetPadding_forAlignmentOnly[328];
			int32_t ___NbStripesSoFar_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___TotalLength_OffsetPadding[336];
			int64_t ___TotalLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___TotalLength_OffsetPadding_forAlignmentOnly[336];
			int64_t ___TotalLength_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Seed_OffsetPadding[344];
			uint64_t ___Seed;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Seed_OffsetPadding_forAlignmentOnly[344];
			uint64_t ___Seed_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SecretKey_OffsetPadding[352];
			uint8_t ___SecretKey;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SecretKey_OffsetPadding_forAlignmentOnly[352];
			uint8_t ___SecretKey_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ____PadEnd_OffsetPadding[540];
			uint8_t ____PadEnd;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ____PadEnd_OffsetPadding_forAlignmentOnly[540];
			uint8_t ____PadEnd_forAlignmentOnly;
		};
	};
};
struct U3CBitsU3Ee__FixedBuffer_tFED81968B5AEB075B5560B55A16A31C5F01A83BD 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3CBitsU3Ee__FixedBuffer_tFED81968B5AEB075B5560B55A16A31C5F01A83BD__padding[32];
	};
};
struct HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259 
{
	uint8_t* ___Ptr;
	ConnectionId_tEA78CDC27F3C855E62B4A8046ECAFF5DB06128EB* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251 
{
	uint8_t* ___Ptr;
	ConnectionToken_tC4332AD93CD9451E95FE2AD7805E547B2A2A9F52* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4 
{
	uint8_t* ___Ptr;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA 
{
	uint8_t* ___Ptr;
	FixedString64Bytes_t0F1B6FFAFD8C15898CD77D91A79AB36AA078E0A5* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B 
{
	uint8_t* ___Ptr;
	int32_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F 
{
	uint8_t* ___Ptr;
	uint64_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6 
{
	int32_t* ___Ptr;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___m_Capacity;
	int32_t ___m_Filled;
	int32_t ___m_Write;
	int32_t ___m_Read;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
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
struct NativeArrayOptions_t3E979EEF4B4840228A7692A97DA07553C6465F1D 
{
	int32_t ___value__;
};
struct TextureFormat_t87A73E4A3850D3410DC211676FC14B94226C1C1D 
{
	int32_t ___value__;
};
struct UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 
{
	uint64_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2 
{
	intptr_t ___m_FirstBlock;
	intptr_t ___m_LastBlock;
	int32_t ___m_MaxItems;
	int32_t ___m_CurrentRead;
	uint8_t* ___m_CurrentWriteBlockTLS;
};
struct UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C 
{
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___Next;
	U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116 ___Data;
};
struct UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 
{
	void* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___Byte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___Byte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte1_OffsetPadding[1];
			uint8_t ___Byte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___Byte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte2_OffsetPadding[2];
			uint8_t ___Byte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___Byte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte3_OffsetPadding[3];
			uint8_t ___Byte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___Byte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte4_OffsetPadding[4];
			uint8_t ___Byte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___Byte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte5_OffsetPadding[5];
			uint8_t ___Byte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___Byte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte6_OffsetPadding[6];
			uint8_t ___Byte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___Byte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte7_OffsetPadding[7];
			uint8_t ___Byte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___Byte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte8_OffsetPadding[8];
			uint8_t ___Byte8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte8_OffsetPadding_forAlignmentOnly[8];
			uint8_t ___Byte8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte9_OffsetPadding[9];
			uint8_t ___Byte9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte9_OffsetPadding_forAlignmentOnly[9];
			uint8_t ___Byte9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte10_OffsetPadding[10];
			uint8_t ___Byte10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte10_OffsetPadding_forAlignmentOnly[10];
			uint8_t ___Byte10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte11_OffsetPadding[11];
			uint8_t ___Byte11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte11_OffsetPadding_forAlignmentOnly[11];
			uint8_t ___Byte11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte12_OffsetPadding[12];
			uint8_t ___Byte12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte12_OffsetPadding_forAlignmentOnly[12];
			uint8_t ___Byte12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte13_OffsetPadding[13];
			uint8_t ___Byte13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte13_OffsetPadding_forAlignmentOnly[13];
			uint8_t ___Byte13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte14_OffsetPadding[14];
			uint8_t ___Byte14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte14_OffsetPadding_forAlignmentOnly[14];
			uint8_t ___Byte14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Byte15_OffsetPadding[15];
			uint8_t ___Byte15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Byte15_OffsetPadding_forAlignmentOnly[15];
			uint8_t ___Byte15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___SByte0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___SByte0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte1_OffsetPadding[1];
			int8_t ___SByte1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___SByte1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte2_OffsetPadding[2];
			int8_t ___SByte2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___SByte2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte3_OffsetPadding[3];
			int8_t ___SByte3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___SByte3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte4_OffsetPadding[4];
			int8_t ___SByte4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___SByte4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte5_OffsetPadding[5];
			int8_t ___SByte5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___SByte5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte6_OffsetPadding[6];
			int8_t ___SByte6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___SByte6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte7_OffsetPadding[7];
			int8_t ___SByte7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___SByte7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte8_OffsetPadding[8];
			int8_t ___SByte8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte8_OffsetPadding_forAlignmentOnly[8];
			int8_t ___SByte8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte9_OffsetPadding[9];
			int8_t ___SByte9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte9_OffsetPadding_forAlignmentOnly[9];
			int8_t ___SByte9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte10_OffsetPadding[10];
			int8_t ___SByte10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte10_OffsetPadding_forAlignmentOnly[10];
			int8_t ___SByte10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte11_OffsetPadding[11];
			int8_t ___SByte11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte11_OffsetPadding_forAlignmentOnly[11];
			int8_t ___SByte11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte12_OffsetPadding[12];
			int8_t ___SByte12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte12_OffsetPadding_forAlignmentOnly[12];
			int8_t ___SByte12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte13_OffsetPadding[13];
			int8_t ___SByte13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte13_OffsetPadding_forAlignmentOnly[13];
			int8_t ___SByte13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte14_OffsetPadding[14];
			int8_t ___SByte14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte14_OffsetPadding_forAlignmentOnly[14];
			int8_t ___SByte14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SByte15_OffsetPadding[15];
			int8_t ___SByte15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SByte15_OffsetPadding_forAlignmentOnly[15];
			int8_t ___SByte15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___UShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___UShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort1_OffsetPadding[2];
			uint16_t ___UShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___UShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort2_OffsetPadding[4];
			uint16_t ___UShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___UShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort3_OffsetPadding[6];
			uint16_t ___UShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___UShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort4_OffsetPadding[8];
			uint16_t ___UShort4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort4_OffsetPadding_forAlignmentOnly[8];
			uint16_t ___UShort4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort5_OffsetPadding[10];
			uint16_t ___UShort5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort5_OffsetPadding_forAlignmentOnly[10];
			uint16_t ___UShort5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort6_OffsetPadding[12];
			uint16_t ___UShort6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort6_OffsetPadding_forAlignmentOnly[12];
			uint16_t ___UShort6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UShort7_OffsetPadding[14];
			uint16_t ___UShort7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UShort7_OffsetPadding_forAlignmentOnly[14];
			uint16_t ___UShort7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___SShort0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___SShort0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort1_OffsetPadding[2];
			int16_t ___SShort1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___SShort1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort2_OffsetPadding[4];
			int16_t ___SShort2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___SShort2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort3_OffsetPadding[6];
			int16_t ___SShort3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___SShort3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort4_OffsetPadding[8];
			int16_t ___SShort4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort4_OffsetPadding_forAlignmentOnly[8];
			int16_t ___SShort4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort5_OffsetPadding[10];
			int16_t ___SShort5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort5_OffsetPadding_forAlignmentOnly[10];
			int16_t ___SShort5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort6_OffsetPadding[12];
			int16_t ___SShort6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort6_OffsetPadding_forAlignmentOnly[12];
			int16_t ___SShort6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SShort7_OffsetPadding[14];
			int16_t ___SShort7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SShort7_OffsetPadding_forAlignmentOnly[14];
			int16_t ___SShort7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___UInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___UInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt1_OffsetPadding[4];
			uint32_t ___UInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___UInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt2_OffsetPadding[8];
			uint32_t ___UInt2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt2_OffsetPadding_forAlignmentOnly[8];
			uint32_t ___UInt2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___UInt3_OffsetPadding[12];
			uint32_t ___UInt3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___UInt3_OffsetPadding_forAlignmentOnly[12];
			uint32_t ___UInt3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___SInt0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___SInt0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt1_OffsetPadding[4];
			int32_t ___SInt1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___SInt1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt2_OffsetPadding[8];
			int32_t ___SInt2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt2_OffsetPadding_forAlignmentOnly[8];
			int32_t ___SInt2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SInt3_OffsetPadding[12];
			int32_t ___SInt3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SInt3_OffsetPadding_forAlignmentOnly[12];
			int32_t ___SInt3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___ULong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___ULong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___ULong1_OffsetPadding[8];
			uint64_t ___ULong1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___ULong1_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___ULong1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___SLong0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___SLong0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SLong1_OffsetPadding[8];
			int64_t ___SLong1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SLong1_OffsetPadding_forAlignmentOnly[8];
			int64_t ___SLong1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___Float0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___Float0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float1_OffsetPadding[4];
			float ___Float1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float1_OffsetPadding_forAlignmentOnly[4];
			float ___Float1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float2_OffsetPadding[8];
			float ___Float2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float2_OffsetPadding_forAlignmentOnly[8];
			float ___Float2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Float3_OffsetPadding[12];
			float ___Float3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Float3_OffsetPadding_forAlignmentOnly[12];
			float ___Float3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___Double0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___Double0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Double1_OffsetPadding[8];
			double ___Double1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Double1_OffsetPadding_forAlignmentOnly[8];
			double ___Double1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Lo64;
		};
		#pragma pack(pop, tp)
		struct
		{
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Lo64_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Hi64_OffsetPadding[8];
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Hi64;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Hi64_OffsetPadding_forAlignmentOnly[8];
			v64_t9C4037532D386FF1E9B95E5FBD01FEF472AC1F96 ___Hi64_forAlignmentOnly;
		};
	};
};
struct Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC 
{
	intptr_t ___Pointer;
	int32_t ___Items;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84 
{
	uint8_t* ___m_pointer;
	int64_t ___m_bytes;
	Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 ___m_union;
};
struct AsyncConversionStatus_tB9035BBA640774DAFF34FEEE5DF141A2F24E1236 
{
	int32_t ___value__;
};
struct Transformation_t26ED8CF20E035506740A8504E00ECD67AF5FD137 
{
	int32_t ___value__;
};
struct Provider_t0D7436E7EFA82C29EF9482B1C801F64458C343A8  : public SubsystemProvider_1_t7F23470F737E4D41A109340894B9E2BB7F170781
{
};
struct StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020 
{
	StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A ___State;
};
struct StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 
{
	U3CBitsU3Ee__FixedBuffer_tFED81968B5AEB075B5560B55A16A31C5F01A83BD ___Bits;
};
struct NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67 
{
	UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 ___m_UntypedListData;
};
struct Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 
{
	Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC ___Range;
	int32_t ___BytesPerItem;
	int32_t ___AllocatedItems;
	uint8_t ___Log2Alignment;
	uint8_t ___Padding0;
	uint16_t ___Padding1;
	uint32_t ___Padding2;
};
struct ConversionParams_t062706B15E2C508C54473A1FD72013C4381CCB62 
{
	RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 ___m_InputRect;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___m_OutputDimensions;
	int32_t ___m_Format;
	int32_t ___m_Transformation;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458 
{
	Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 ___m_BlockData;
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___m_CurrentBlock;
	uint8_t* ___m_CurrentPtr;
	uint8_t* ___m_CurrentBlockEnd;
	int32_t ___m_RemainingItemCount;
	int32_t ___m_LastBlockSize;
};
struct Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F 
{
	Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 ___m_BlockData;
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___m_CurrentBlock;
	uint8_t* ___m_CurrentPtr;
	uint8_t* ___m_CurrentBlockEnd;
	int32_t ___m_ForeachIndex;
	int32_t ___m_ElementCount;
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___m_FirstBlock;
	int32_t ___m_FirstOffset;
	int32_t ___m_NumberOfBlocks;
	int32_t ___m_ThreadIndex;
};
struct AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2 
{
	Api_tAE210A8378E537AFD1FA4B99562229CE842377FB* ___m_Api;
	int32_t ___m_RequestId;
	ConversionParams_t062706B15E2C508C54473A1FD72013C4381CCB62 ___U3CconversionParamsU3Ek__BackingField;
};
struct AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2_marshaled_pinvoke
{
	Api_tAE210A8378E537AFD1FA4B99562229CE842377FB* ___m_Api;
	int32_t ___m_RequestId;
	ConversionParams_t062706B15E2C508C54473A1FD72013C4381CCB62 ___U3CconversionParamsU3Ek__BackingField;
};
struct AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2_marshaled_com
{
	Api_tAE210A8378E537AFD1FA4B99562229CE842377FB* ___m_Api;
	int32_t ___m_RequestId;
	ConversionParams_t062706B15E2C508C54473A1FD72013C4381CCB62 ___U3CconversionParamsU3Ek__BackingField;
};
struct Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30_StaticFields
{
	Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30* ___defaultComparer;
};
struct Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563_StaticFields
{
	Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* ___defaultComparer;
};
struct Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B_StaticFields
{
	Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* ___defaultComparer;
};
struct Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98_StaticFields
{
	Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* ___defaultComparer;
};
struct Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985_StaticFields
{
	Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* ___defaultComparer;
};
struct EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields
{
	EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* ___defaultComparer;
};
struct EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields
{
	EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* ___defaultComparer;
};
struct EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields
{
	EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* ___defaultComparer;
};
struct EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields
{
	EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* ___defaultComparer;
};
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9_StaticFields
{
	EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* ___defaultComparer;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_StaticFields
{
	UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___crctab;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct UIntPtr_t_StaticFields
{
	uintptr_t ___Zero;
};
struct StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_StaticFields
{
	int32_t ___SECRET_LIMIT;
	int32_t ___NB_STRIPES_PER_BLOCK;
	int32_t ___INTERNAL_BUFFER_SIZE;
	int32_t ___INTERNAL_BUFFER_STRIPES;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_gshared_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_gshared_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_value, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6_gshared (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633_gshared (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7_gshared (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917_gshared (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30* Comparer_1_get_Default_m84FF70BAB6A30BC2A0EABE8B0E58FCBD8F40C8FB_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235_gshared (int32_t ___0_len, int32_t ___1_imm8, uint8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8_gshared (int32_t ___0_len, int32_t ___1_imm8, int16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455_gshared (int32_t ___0_len, int32_t ___1_imm8, int8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1_gshared (int32_t ___0_len, int32_t ___1_imm8, uint16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A_gshared (uint8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3_gshared (int16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171_gshared (int8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D_gshared (uint16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 AsyncConversion_GetData_TisIl2CppFullySharedGenericStruct_m55B782125B0D4D0B65C9018372619ED6941CDFDA_gshared (AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool NativeArray_1_get_IsCreated_m478F812F31DEC928EC9D697C47C7E188CCA0010F_gshared_inline (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m78ECC3FE24D545255D9CFABB81FC34CA6CC2A4A7_gshared (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mFD9836AFB0757330727FED396E637FB060E30DF5_gshared (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1_gshared (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_mC5F44294D762B301009B393430DA9708D93DFBA1_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_m9B6FC2F3A48E1F92C8BA73C9A9801200E2124091_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mEFDB11310E50096B062049FA90AC4E5950D68E88_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mBC2C631257DB33D5016220F5C7A5427FF2DACFF6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m3EB9C6E6DBEE5EBF53B76E36EC79986A0597AE52_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m0593078BB9DC842E2FE2C88E802B606CDC972402_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_mE0B20AEA610B5E2F0CC79058F8B1773FBD33256F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_m35FC0B97B1F13FB0FAA471381CCBB0CB3087BC97_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_m25F773608FD4EA5E754AA43D5713B5168C86E212_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_mA92165B534B206808B571FE7817873636583F50A_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m88ED79EB396A32F9D6D47E040DD8509165D2061A_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m930BE4239F776EB5AE029CD112988F6AA9DB8F8B_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m42EC081A96F2D205655A9102710A6D4ADD494933_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m5565CF16739E9A5FFA05B4531E1F7DC4DE0ECA97_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_m9CFC6F1A283DF0509BEA73ABCC30711204347AEE_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_mEC999A534156D6D8DD89428B7B1F3F089410D7A4_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D446ED46691A93FCA713FB662C464A32EC57539_gshared (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8_gshared (const RuntimeMethod* method) ;

inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9 (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9 (uint64_t ___0_offset, int32_t ___1_alignmentPowerOfTwo, const RuntimeMethod* method) ;
inline int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (void*, int32_t, const RuntimeMethod*))UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_gshared_inline)(___0_source, ___1_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177 (void* ___0_destination, void* ___1_source, int64_t ___2_size, const RuntimeMethod* method) ;
inline int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*, const RuntimeMethod*))Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_gshared)(__this, method);
}
inline void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method)
{
	((  void (*) (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2_gshared)((Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*)__this, il2cppRetVal, method);
}
inline void UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method)
{
	((  void (*) (void*, int32_t*, const RuntimeMethod*))UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_gshared_inline)(___0_ptr, ___1_output, method);
}
inline void Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*, int32_t*, const RuntimeMethod*))Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9_gshared)(__this, ___0_value, method);
}
inline void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Reader_ReadNext_m7C9150A60E622C8581A3E80C8DD1AD71D043BF6A (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t ___0_structSize, const RuntimeMethod* method) ;
inline void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_value, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method)
{
	((  void (*) (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372_gshared)(__this, ___0_value, ___1_allocator, method);
}
inline void* Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_length, const RuntimeMethod* method)
{
	return ((  void* (*) (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*, int32_t*, const RuntimeMethod*))Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC_gshared)(__this, ___0_length, method);
}
inline Il2CppFullySharedGenericStruct* Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6 (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method)
{
	return ((  Il2CppFullySharedGenericStruct* (*) (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458*, const RuntimeMethod*))Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Reader_ReadUnsafePtr_m6CDEF727114990BC4C2DF321BE752F229104A888 (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, int32_t ___0_size, const RuntimeMethod* method) ;
inline Il2CppFullySharedGenericStruct* Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633 (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method)
{
	return ((  Il2CppFullySharedGenericStruct* (*) (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458*, const RuntimeMethod*))Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Writer_Allocate_m85F9D4FF8746C0A59DC23A9003398A6D9D42526D (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, int32_t ___0_size, const RuntimeMethod* method) ;
inline Il2CppFullySharedGenericStruct* Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7 (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, const RuntimeMethod* method)
{
	return ((  Il2CppFullySharedGenericStruct* (*) (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*, const RuntimeMethod*))Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7_gshared)(__this, method);
}
inline void Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917 (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*, Il2CppFullySharedGenericStruct, const RuntimeMethod*))Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917_gshared)((Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*)__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int64_CompareTo_m63A0BDA03C5B1DEB7387B1C53D6BFD961E4F5490 (int64_t* __this, int64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586 (int32_t* __this, int32_t ___0_value, const RuntimeMethod* method) ;
inline EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_gshared_inline)(method);
}
inline Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30* Comparer_1_get_Default_m84FF70BAB6A30BC2A0EABE8B0E58FCBD8F40C8FB (const RuntimeMethod* method)
{
	return ((  Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30* (*) (const RuntimeMethod*))Comparer_1_get_Default_m84FF70BAB6A30BC2A0EABE8B0E58FCBD8F40C8FB_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01 (StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6* __this, int32_t ___0_aindex, int32_t ___1_bindex, bool ___2_val, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78 (StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6* __this, int32_t ___0_aindex, int32_t ___1_bindex, const RuntimeMethod* method) ;
inline EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_gshared_inline)(method);
}
inline Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407 (const RuntimeMethod* method)
{
	return ((  Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* (*) (const RuntimeMethod*))Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407_gshared)(method);
}
inline EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_gshared_inline)(method);
}
inline Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F (const RuntimeMethod* method)
{
	return ((  Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* (*) (const RuntimeMethod*))Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F_gshared)(method);
}
inline EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_gshared_inline)(method);
}
inline Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36 (const RuntimeMethod* method)
{
	return ((  Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* (*) (const RuntimeMethod*))Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36_gshared)(method);
}
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint8_t*, int32_t, uint8_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123 (int32_t ___0_len, int32_t ___1_imm8, int32_t ___2_intRes2, const RuntimeMethod* method) ;
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960 (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int16_t*, int32_t, int16_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int8_t*, int32_t, int8_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
inline int32_t Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint16_t*, int32_t, uint16_t*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB_gshared)(___0_a, ___1_alen, ___2_b, ___3_blen, ___4_len, ___5_imm8, ___6_allOnes, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235 (int32_t ___0_len, int32_t ___1_imm8, uint8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, uint8_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8 (int32_t ___0_len, int32_t ___1_imm8, int16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, int16_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455 (int32_t ___0_len, int32_t ___1_imm8, int8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, int8_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1 (int32_t ___0_len, int32_t ___1_imm8, uint16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method)
{
	return ((  v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 (*) (int32_t, int32_t, uint16_t, int32_t, const RuntimeMethod*))Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1_gshared)(___0_len, ___1_imm8, ___2_allOnesT, ___3_intRes2, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A (uint8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint8_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A_gshared)(___0_ptr, ___1_max, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3 (int16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int16_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3_gshared)(___0_ptr, ___1_max, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171 (int8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (int8_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171_gshared)(___0_ptr, ___1_max, method);
}
inline int32_t Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D (uint16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method)
{
	return ((  int32_t (*) (uint16_t*, int32_t, const RuntimeMethod*))Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D_gshared)(___0_ptr, ___1_max, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AsyncConversion_get_status_mB3A873407AF4E202A39758599DCEE52BEC196E2A (AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF (intptr_t ___0_value, const RuntimeMethod* method) ;
inline NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 AsyncConversion_GetData_TisIl2CppFullySharedGenericStruct_m55B782125B0D4D0B65C9018372619ED6941CDFDA (AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2* __this, const RuntimeMethod* method)
{
	return ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2*, const RuntimeMethod*))AsyncConversion_GetData_TisIl2CppFullySharedGenericStruct_m55B782125B0D4D0B65C9018372619ED6941CDFDA_gshared)(__this, method);
}
inline bool NativeArray_1_get_IsCreated_m478F812F31DEC928EC9D697C47C7E188CCA0010F_inline (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m478F812F31DEC928EC9D697C47C7E188CCA0010F_gshared_inline)(__this, method);
}
inline void NativeArray_1_Dispose_m78ECC3FE24D545255D9CFABB81FC34CA6CC2A4A7 (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, const RuntimeMethod* method)
{
	((  void (*) (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70*, const RuntimeMethod*))NativeArray_1_Dispose_m78ECC3FE24D545255D9CFABB81FC34CA6CC2A4A7_gshared)(__this, method);
}
inline void NativeArray_1__ctor_mFD9836AFB0757330727FED396E637FB060E30DF5 (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method)
{
	((  void (*) (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70*, int32_t, int32_t, int32_t, const RuntimeMethod*))NativeArray_1__ctor_mFD9836AFB0757330727FED396E637FB060E30DF5_gshared)(__this, ___0_length, ___1_allocator, ___2_options, method);
}
inline void NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1 (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method)
{
	((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, int32_t, int32_t, const RuntimeMethod*))NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1_gshared)(__this, ___0_length, ___1_allocator, ___2_options, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5 (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, void* ___0_input, int32_t ___1_length, const RuntimeMethod* method) ;
inline void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method)
{
	((  void (*) (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_gshared)(__this, ___0_input, method);
}
inline MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3 (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method)
{
	return ((  MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* (*) (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared)(___0_oldPointer, ___1_oldCount, ___2_newCount, ___3_allocator, method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_mC5F44294D762B301009B393430DA9708D93DFBA1_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_mC5F44294D762B301009B393430DA9708D93DFBA1_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_m9B6FC2F3A48E1F92C8BA73C9A9801200E2124091 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_m9B6FC2F3A48E1F92C8BA73C9A9801200E2124091_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380 (void* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, int64_t ___4_size, int32_t ___5_align, const RuntimeMethod* method) ;
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mEFDB11310E50096B062049FA90AC4E5950D68E88_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mEFDB11310E50096B062049FA90AC4E5950D68E88_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mBC2C631257DB33D5016220F5C7A5427FF2DACFF6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mBC2C631257DB33D5016220F5C7A5427FF2DACFF6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m3EB9C6E6DBEE5EBF53B76E36EC79986A0597AE52_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m3EB9C6E6DBEE5EBF53B76E36EC79986A0597AE52_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m0593078BB9DC842E2FE2C88E802B606CDC972402 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m0593078BB9DC842E2FE2C88E802B606CDC972402_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_mE0B20AEA610B5E2F0CC79058F8B1773FBD33256F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_mE0B20AEA610B5E2F0CC79058F8B1773FBD33256F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_m35FC0B97B1F13FB0FAA471381CCBB0CB3087BC97 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_m35FC0B97B1F13FB0FAA471381CCBB0CB3087BC97_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_m25F773608FD4EA5E754AA43D5713B5168C86E212_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_m25F773608FD4EA5E754AA43D5713B5168C86E212_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_mA92165B534B206808B571FE7817873636583F50A (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_mA92165B534B206808B571FE7817873636583F50A_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m88ED79EB396A32F9D6D47E040DD8509165D2061A_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m88ED79EB396A32F9D6D47E040DD8509165D2061A_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m930BE4239F776EB5AE029CD112988F6AA9DB8F8B (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m930BE4239F776EB5AE029CD112988F6AA9DB8F8B_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m42EC081A96F2D205655A9102710A6D4ADD494933_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m42EC081A96F2D205655A9102710A6D4ADD494933_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m5565CF16739E9A5FFA05B4531E1F7DC4DE0ECA97 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m5565CF16739E9A5FFA05B4531E1F7DC4DE0ECA97_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_m9CFC6F1A283DF0509BEA73ABCC30711204347AEE_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_m9CFC6F1A283DF0509BEA73ABCC30711204347AEE_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_mEC999A534156D6D8DD89428B7B1F3F089410D7A4 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_mEC999A534156D6D8DD89428B7B1F3F089410D7A4_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_gshared)(method);
}
inline int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline)(method);
}
inline int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05 (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_gshared)(method);
}
inline void UnsafeUtility_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D446ED46691A93FCA713FB662C464A32EC57539 (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method)
{
	((  void (*) (void*, int32_t*, const RuntimeMethod*))UnsafeUtility_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D446ED46691A93FCA713FB662C464A32EC57539_gshared)(___0_ptr, ___1_output, method);
}
inline EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377_gshared)(method);
}
inline EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B_gshared)(method);
}
inline EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D_gshared)(method);
}
inline EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8_gshared)(method);
}
// Method Definition Index: 138065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_mA88A16DC097E207AD6CE15E89D3B94DBB01BDACE_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5274));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5275));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5276));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
// Method Definition Index: 138065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_m28D19B06528A4614AF9C3E29DC8274DE067868D8_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5274));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5275));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5276));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
// Method Definition Index: 138065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m3CD9CD3C768BBCC83DD02B2C76300A03AF1B1AD6_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5274));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5275));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5276));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
// Method Definition Index: 138065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisIl2CppFullySharedGenericAny_m8B414261A078E3FE7517FAF2F9E944969F6B73E2_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5274));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5275));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5276));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = ((  RuntimeObject* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_PropertiesModule + 5277));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
// Method Definition Index: 107190
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	void* V_2 = NULL;
	bool V_3 = false;
	int32_t V_4 = 0;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31157));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 31158));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31159));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:392>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31160));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31161));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31161));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:396>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31162));
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_2 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:397>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31163));
		void* L_3 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31164));
		int32_t L_4;
		L_4 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31164));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31165));
		bool L_5;
		L_5 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9((uint64_t)((int64_t)(uint64_t)((uintptr_t)(intptr_t)L_3)), L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31165));
		V_3 = L_5;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31166));
		bool L_6 = V_3;
		if (!L_6)
		{
			goto IL_002f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:398>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31167));
		void* L_7 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31168));
		int32_t L_8;
		L_8 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline(L_7, 0, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31168));
		V_1 = L_8;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31169));
		goto IL_003b;
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:400>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31170));
		void* L_9 = V_2;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31171));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)((uintptr_t)(&V_1)), L_9, ((int64_t)L_10), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31171));
	}

IL_003b:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:402>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31172));
		int32_t L_11 = __this->___Offset;
		int32_t L_12 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_11, L_12));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:403>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31173));
		int32_t L_13 = V_1;
		V_4 = L_13;
		goto IL_004e;
	}

IL_004e:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:404>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31174));
		int32_t L_14 = V_4;
		return L_14;
	}
}
IL2CPP_EXTERN_C  int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 107190
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 3));
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	const Il2CppFullySharedGenericStruct L_13 = L_8;
	const Il2CppFullySharedGenericStruct L_14 = L_8;
	int32_t V_0 = 0;
	Il2CppFullySharedGenericStruct V_1 = alloca(SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	memset(V_1, 0, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	void* V_2 = NULL;
	bool V_3 = false;
	Il2CppFullySharedGenericStruct V_4 = alloca(SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	memset(V_4, 0, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), V_1, (&V_2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31157));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 31158));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31159));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:392>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31160));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31161));
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31161));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:396>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31162));
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_2 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:397>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31163));
		void* L_3 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31164));
		int32_t L_4;
		L_4 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31164));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31165));
		bool L_5;
		L_5 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9((uint64_t)((int64_t)(uint64_t)((uintptr_t)(intptr_t)L_3)), L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31165));
		V_3 = L_5;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31166));
		bool L_6 = V_3;
		if (!L_6)
		{
			goto IL_002f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:398>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31167));
		void* L_7 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31168));
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), NULL, L_7, 0, (Il2CppFullySharedGenericStruct*)L_8);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31168));
		il2cpp_codegen_memcpy(V_1, L_8, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31169));
		goto IL_003b;
	}

IL_002f:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:400>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31170));
		void* L_9 = V_2;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31171));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)((uintptr_t)(Il2CppFullySharedGenericStruct*)V_1), L_9, ((int64_t)L_10), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31171));
	}

IL_003b:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:402>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31172));
		int32_t L_11 = __this->___Offset;
		int32_t L_12 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_11, L_12));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:403>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31173));
		il2cpp_codegen_memcpy(L_13, V_1, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		il2cpp_codegen_memcpy(V_4, L_13, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		goto IL_004e;
	}

IL_004e:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:404>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31174));
		il2cpp_codegen_memcpy(L_14, V_4, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		il2cpp_codegen_memcpy(il2cppRetVal, L_14, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		return;
	}
}
IL2CPP_EXTERN_C  void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method)
{
	Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*>(__this + _offset);
	Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2(_thisAdjusted, il2cppRetVal, method);
	return;
}
// Method Definition Index: 107189
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	void* V_1 = NULL;
	bool V_2 = false;
	void* V_3 = NULL;
	int32_t* V_4 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31138));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 31139));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31140));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:371>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31141));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31142));
		int32_t L_0;
		L_0 = UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31142));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31143));
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_1 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:375>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31144));
		void* L_3 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31145));
		int32_t L_4;
		L_4 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31145));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31146));
		bool L_5;
		L_5 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9((uint64_t)((int64_t)(uint64_t)((uintptr_t)(intptr_t)L_3)), L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31146));
		V_2 = L_5;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31147));
		bool L_6 = V_2;
		if (!L_6)
		{
			goto IL_002f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:376>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31148));
		void* L_7 = V_1;
		int32_t* L_8 = ___0_value;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31149));
		UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_inline(L_7, L_8, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31149));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31150));
		goto IL_0044;
	}

IL_002f:
	{
		int32_t* L_9 = ___0_value;
		V_4 = L_9;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:378>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31151));
		int32_t* L_10 = V_4;
		V_3 = (void*)((uintptr_t)L_10);
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:378>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31152));
		void* L_11 = V_3;
		void* L_12 = V_1;
		int32_t L_13 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31153));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_11, L_12, ((int64_t)L_13), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31153));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31154));
		V_4 = (int32_t*)((uintptr_t)0);
	}

IL_0044:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:380>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31155));
		int32_t L_14 = __this->___Offset;
		int32_t L_15 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_14, L_15));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:381>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31156));
		return;
	}
}
IL2CPP_EXTERN_C  void Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9_AdjustorThunk (RuntimeObject* __this, int32_t* ___0_value, const RuntimeMethod* method)
{
	Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*>(__this + _offset);
	Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 107189
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* ___0_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	void* V_1 = NULL;
	bool V_2 = false;
	void* V_3 = NULL;
	Il2CppFullySharedGenericStruct* V_4 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31138));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 31139));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31140));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:371>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31141));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31142));
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31142));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31143));
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_1 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:375>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31144));
		void* L_3 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31145));
		int32_t L_4;
		L_4 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31145));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31146));
		bool L_5;
		L_5 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9((uint64_t)((int64_t)(uint64_t)((uintptr_t)(intptr_t)L_3)), L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31146));
		V_2 = L_5;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31147));
		bool L_6 = V_2;
		if (!L_6)
		{
			goto IL_002f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:376>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31148));
		void* L_7 = V_1;
		Il2CppFullySharedGenericStruct* L_8 = ___0_value;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31149));
		((  void (*) (void*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_7, L_8, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31149));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31150));
		goto IL_0044;
	}

IL_002f:
	{
		Il2CppFullySharedGenericStruct* L_9 = ___0_value;
		V_4 = L_9;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:378>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31151));
		Il2CppFullySharedGenericStruct* L_10 = V_4;
		V_3 = (void*)((uintptr_t)L_10);
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:378>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31152));
		void* L_11 = V_3;
		void* L_12 = V_1;
		int32_t L_13 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31153));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_11, L_12, ((int64_t)L_13), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31153));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31154));
		V_4 = (Il2CppFullySharedGenericStruct*)((uintptr_t)0);
	}

IL_0044:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:380>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31155));
		int32_t L_14 = __this->___Offset;
		int32_t L_15 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_14, L_15));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:381>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31156));
		return;
	}
}
IL2CPP_EXTERN_C  void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct* ___0_value, const RuntimeMethod* method)
{
	Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*>(__this + _offset);
	Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 107192
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_value, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	bool V_2 = false;
	void* V_3 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_value), (&___1_allocator));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31185));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 31186));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31187));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:431>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31188));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31189));
		int32_t L_0;
		L_0 = Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774(__this, Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31189));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:432>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31190));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_value;
		int32_t L_2 = V_0;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31191));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_4;
		L_4 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (int32_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_2, L_3, (int32_t)0, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31191));
		*(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)L_1 = L_4;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:433>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31192));
		int32_t L_5 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31193));
		int32_t L_6;
		L_6 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31193));
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_5, L_6));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:434>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31194));
		int32_t L_7 = V_1;
		V_2 = (bool)((((int32_t)L_7) > ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31195));
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0044;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31196));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:436>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31197));
		int32_t L_9 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31198));
		void* L_10;
		L_10 = Reader_ReadNext_m7C9150A60E622C8581A3E80C8DD1AD71D043BF6A(__this, L_9, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31198));
		V_3 = L_10;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:437>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31199));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_11 = ___0_value;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_12 = (*(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)L_11);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31200));
		void* L_13;
		L_13 = ((  void* (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(L_12, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31200));
		void* L_14 = V_3;
		int32_t L_15 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31201));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_13, L_14, ((int64_t)L_15), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31201));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31202));
	}

IL_0044:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:439>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31203));
		return;
	}
}
IL2CPP_EXTERN_C  void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372_AdjustorThunk (RuntimeObject* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_value, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method)
{
	Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*>(__this + _offset);
	Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372(_thisAdjusted, ___0_value, ___1_allocator, method);
}
// Method Definition Index: 107193
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC_gshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_length, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VoidU2A_t104EAEFBD2D237A8C29618913DA9B4D99355E965_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	void* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_length));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31204));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 31205));
	uintptr_t G_B3_0;
	memset((&G_B3_0), 0, sizeof(G_B3_0));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31206));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:454>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31207));
		int32_t* L_0 = ___0_length;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31208));
		int32_t L_1;
		L_1 = Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774(__this, Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31208));
		*((int32_t*)L_0) = (int32_t)L_1;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:455>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31209));
		int32_t* L_2 = ___0_length;
		int32_t L_3 = *((int32_t*)L_2);
		if (!L_3)
		{
			goto IL_001d;
		}
	}
	{
		int32_t* L_4 = ___0_length;
		int32_t L_5 = *((int32_t*)L_4);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31210));
		int32_t L_6;
		L_6 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31210));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31211));
		void* L_7;
		L_7 = Reader_ReadNext_m7C9150A60E622C8581A3E80C8DD1AD71D043BF6A(__this, ((int32_t)il2cpp_codegen_multiply(L_5, L_6)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31211));
		G_B3_0 = ((uintptr_t)(intptr_t)(L_7));
		goto IL_001f;
	}

IL_001d:
	{
		G_B3_0 = ((uintptr_t)0);
	}

IL_001f:
	{
		V_0 = (void*)G_B3_0;
		goto IL_0022;
	}

IL_0022:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeAppendBuffer.cs:456>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 31212));
		void* L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C  void* Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC_AdjustorThunk (RuntimeObject* __this, int32_t* ___0_length, const RuntimeMethod* method)
{
	Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6*>(__this + _offset);
	void* _returnValue;
	_returnValue = Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC(_thisAdjusted, ___0_length, method);
	return _returnValue;
}
// Method Definition Index: 107879
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6_gshared (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU2A_t7A03686A8034AF92EF1EA2D09B280EF590D1174D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	uint8_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericStruct* V_3 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39530));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 39531));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39532));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:676>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39533));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39534));
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39534));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:678>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39535));
		uint8_t* L_1 = __this->___m_CurrentPtr;
		V_1 = L_1;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:679>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39536));
		uint8_t* L_2 = V_1;
		int32_t L_3 = V_0;
		uint8_t* L_4 = __this->___m_CurrentBlockEnd;
		V_2 = (bool)((!(((uintptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_2, L_3))) <= ((uintptr_t)L_4)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39537));
		bool L_5 = V_2;
		if (!L_5)
		{
			goto IL_0036;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39538));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:681>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39539));
		UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* L_6 = __this->___m_CurrentBlock;
		NullCheck(L_6);
		UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* L_7 = L_6->___Next;
		NullCheck(L_7);
		U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116* L_8 = (U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116*)(&L_7->___Data);
		uint8_t* L_9 = (uint8_t*)(&L_8->___FixedElementField);
		V_1 = (uint8_t*)((uintptr_t)L_9);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39540));
	}

IL_0036:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:684>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39541));
		uint8_t* L_10 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39542));
		Il2CppFullySharedGenericStruct* L_11;
		L_11 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_10, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39542));
		V_3 = L_11;
		goto IL_003f;
	}

IL_003f:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:685>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39543));
		Il2CppFullySharedGenericStruct* L_12 = V_3;
		return L_12;
	}
}
IL2CPP_EXTERN_C  Il2CppFullySharedGenericStruct* Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458*>(__this + _offset);
	Il2CppFullySharedGenericStruct* _returnValue;
	_returnValue = Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 107878
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633_gshared (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	Il2CppFullySharedGenericStruct* V_1 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39521));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 39522));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39523));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:664>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39524));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39525));
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39525));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:665>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39526));
		int32_t L_1 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39527));
		uint8_t* L_2;
		L_2 = Reader_ReadUnsafePtr_m6CDEF727114990BC4C2DF321BE752F229104A888(__this, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39527));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39528));
		Il2CppFullySharedGenericStruct* L_3;
		L_3 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39528));
		V_1 = L_3;
		goto IL_0016;
	}

IL_0016:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:666>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39529));
		Il2CppFullySharedGenericStruct* L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C  Il2CppFullySharedGenericStruct* Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458*>(__this + _offset);
	Il2CppFullySharedGenericStruct* _returnValue;
	_returnValue = Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 107870
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7_gshared (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	Il2CppFullySharedGenericStruct* V_1 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39429));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 39430));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39431));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:506>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39432));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39433));
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39433));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:507>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39434));
		int32_t L_1 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39435));
		uint8_t* L_2;
		L_2 = Writer_Allocate_m85F9D4FF8746C0A59DC23A9003398A6D9D42526D(__this, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39435));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39436));
		Il2CppFullySharedGenericStruct* L_3;
		L_3 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39436));
		V_1 = L_3;
		goto IL_0016;
	}

IL_0016:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:508>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39437));
		Il2CppFullySharedGenericStruct* L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C  Il2CppFullySharedGenericStruct* Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*>(__this + _offset);
	Il2CppFullySharedGenericStruct* _returnValue;
	_returnValue = Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 107869
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917_gshared (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7);
	Il2CppFullySharedGenericStruct* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 2)) ? ___0_value : &___0_value));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39422));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 39423));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39424));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:492>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39425));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39426));
		Il2CppFullySharedGenericStruct* L_0;
		L_0 = ((  Il2CppFullySharedGenericStruct* (*) (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(__this, il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39426));
		V_0 = L_0;
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:493>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39427));
		Il2CppFullySharedGenericStruct* L_1 = V_0;
		il2cpp_codegen_memcpy(L_2, ___0_value, SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_1, L_2, SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 2), (void**)(Il2CppFullySharedGenericStruct*)L_1, (void*)L_2);
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/UnsafeStream.cs:494>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 39428));
		return;
	}
}
IL2CPP_EXTERN_C  void Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method)
{
	Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*>(__this + _offset);
	Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 116728
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m916056C6D56ED56A8C621B65387940440621885B_gshared (double* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int64_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int64_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	double* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20327));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20328));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20329));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20330));
		il2cpp_codegen_initobj((&V_0), sizeof(int64_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20331));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20332));
		goto IL_006a;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20333));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20334));
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		V_2 = ((int64_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2360>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20335));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20336));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (double*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2362>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20337));
		int64_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0045;
		}
	}
	{
		int64_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int64_t);
		int64_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		int32_t L_12;
		L_12 = Int64_CompareTo_m63A0BDA03C5B1DEB7387B1C53D6BFD961E4F5490((int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0046;
	}

IL_0045:
	{
		G_B4_0 = 1;
	}

IL_0046:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20339));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0065;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20340));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20341));
		double* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(double);
		double* L_17 = V_4;
		double L_18 = (*(double*)L_17);
		*(double*)((double*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20342));
	}

IL_0065:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20344));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20345));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20346));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20347));
		return;
	}
}
// Method Definition Index: 116727
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m9A1DADAD9E0F3273D16A73D963070B45A72D049C_gshared (double* ___0_dptr, void* ___1_base_addr, int64_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int64_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int64_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	double* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20306));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20307));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20308));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2339>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20309));
		il2cpp_codegen_initobj((&V_0), sizeof(int64_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20310));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20311));
		goto IL_0069;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20312));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20313));
		int64_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int64_t L_2 = (*(((int64_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 8))))));
		V_2 = L_2;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2344>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20314));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2345>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20315));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (double*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20316));
		int64_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0044;
		}
	}
	{
		int64_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int64_t);
		int64_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		int32_t L_12;
		L_12 = Int64_CompareTo_m63A0BDA03C5B1DEB7387B1C53D6BFD961E4F5490((int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0045;
	}

IL_0044:
	{
		G_B4_0 = 1;
	}

IL_0045:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20318));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0064;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20319));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2348>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20320));
		double* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(double);
		double* L_17 = V_4;
		double L_18 = (*(double*)L_17);
		*(double*)((double*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20321));
	}

IL_0064:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20322));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20323));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0069:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20324));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20325));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20326));
		return;
	}
}
// Method Definition Index: 116728
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m94F8FFCEA63E0174FFF11E533C79D165E357A272_gshared (int32_t* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int32_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int32_t* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20327));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20328));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20329));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20330));
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20331));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20332));
		goto IL_006a;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20333));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20334));
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		V_2 = ((int64_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2360>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20335));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20336));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2362>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20337));
		int32_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0045;
		}
	}
	{
		int32_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int32_t);
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		int32_t L_12;
		L_12 = Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0046;
	}

IL_0045:
	{
		G_B4_0 = 1;
	}

IL_0046:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20339));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0065;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20340));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20341));
		int32_t* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(int32_t);
		int32_t* L_17 = V_4;
		int32_t L_18 = (*(int32_t*)L_17);
		*(int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20342));
	}

IL_0065:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20344));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20345));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20346));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20347));
		return;
	}
}
// Method Definition Index: 116727
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m75E4DC1575D64C468E29623C2A27062E59A006BB_gshared (int32_t* ___0_dptr, void* ___1_base_addr, int64_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int32_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int32_t* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20306));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20307));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20308));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2339>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20309));
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20310));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20311));
		goto IL_0069;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20312));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20313));
		int64_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int64_t L_2 = (*(((int64_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 8))))));
		V_2 = L_2;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2344>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20314));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2345>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20315));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20316));
		int32_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0044;
		}
	}
	{
		int32_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int32_t);
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		int32_t L_12;
		L_12 = Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0045;
	}

IL_0044:
	{
		G_B4_0 = 1;
	}

IL_0045:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20318));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0064;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20319));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2348>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20320));
		int32_t* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(int32_t);
		int32_t* L_17 = V_4;
		int32_t L_18 = (*(int32_t*)L_17);
		*(int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20321));
	}

IL_0064:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20322));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20323));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0069:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20324));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20325));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20326));
		return;
	}
}
// Method Definition Index: 116728
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m8F3DA1C7D0D9C656F6FB3CCC2747A02B6BDF9E8E_gshared (int64_t* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int64_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int64_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20327));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20328));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20329));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20330));
		il2cpp_codegen_initobj((&V_0), sizeof(int64_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20331));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20332));
		goto IL_006a;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20333));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20334));
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		V_2 = ((int64_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2360>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20335));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20336));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (int64_t*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2362>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20337));
		int64_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0045;
		}
	}
	{
		int64_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int64_t);
		int64_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		int32_t L_12;
		L_12 = Int64_CompareTo_m63A0BDA03C5B1DEB7387B1C53D6BFD961E4F5490((int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0046;
	}

IL_0045:
	{
		G_B4_0 = 1;
	}

IL_0046:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20339));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0065;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20340));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20341));
		int64_t* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(int64_t);
		int64_t* L_17 = V_4;
		int64_t L_18 = (*(int64_t*)L_17);
		*(int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20342));
	}

IL_0065:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20344));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20345));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20346));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20347));
		return;
	}
}
// Method Definition Index: 116727
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m16B5D468730F5B7AFE121394A46B16F4E3F663CB_gshared (int64_t* ___0_dptr, void* ___1_base_addr, int64_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int64_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int64_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	int64_t* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20306));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20307));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20308));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2339>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20309));
		il2cpp_codegen_initobj((&V_0), sizeof(int64_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20310));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20311));
		goto IL_0069;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20312));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20313));
		int64_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int64_t L_2 = (*(((int64_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 8))))));
		V_2 = L_2;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2344>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20314));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2345>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20315));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (int64_t*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20316));
		int64_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0044;
		}
	}
	{
		int64_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int64_t);
		int64_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		int32_t L_12;
		L_12 = Int64_CompareTo_m63A0BDA03C5B1DEB7387B1C53D6BFD961E4F5490((int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0045;
	}

IL_0044:
	{
		G_B4_0 = 1;
	}

IL_0045:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20318));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0064;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20319));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2348>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20320));
		int64_t* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(int64_t);
		int64_t* L_17 = V_4;
		int64_t L_18 = (*(int64_t*)L_17);
		*(int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20321));
	}

IL_0064:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20322));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20323));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0069:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20324));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20325));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20326));
		return;
	}
}
// Method Definition Index: 116728
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBD6B0D9436820A5A075E4DEDAC5F272776C647AD_gshared (float* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int32_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	float* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20327));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20328));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20329));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20330));
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20331));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20332));
		goto IL_006a;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20333));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20334));
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		V_2 = ((int64_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2360>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20335));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20336));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (float*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2362>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20337));
		int32_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0045;
		}
	}
	{
		int32_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int32_t);
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		int32_t L_12;
		L_12 = Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0046;
	}

IL_0045:
	{
		G_B4_0 = 1;
	}

IL_0046:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20339));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0065;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20340));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20341));
		float* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(float);
		float* L_17 = V_4;
		float L_18 = (*(float*)L_17);
		*(float*)((float*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20342));
	}

IL_0065:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20344));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20345));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20346));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20347));
		return;
	}
}
// Method Definition Index: 116727
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m089FE6B150D3770B7C1109D4010EFBE72C0E985B_gshared (float* ___0_dptr, void* ___1_base_addr, int64_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, int32_t* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	float* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20306));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20307));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20308));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2339>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20309));
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20310));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20311));
		goto IL_0069;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20312));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20313));
		int64_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int64_t L_2 = (*(((int64_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 8))))));
		V_2 = L_2;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2344>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20314));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2345>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20315));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (float*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20316));
		int32_t* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0044;
		}
	}
	{
		int32_t* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = sizeof(int32_t);
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		int32_t L_12;
		L_12 = Int32_CompareTo_mFA011811D4447442ED442B4A507BD4267621C586((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		G_B4_0 = ((((int32_t)L_12) < ((int32_t)0))? 1 : 0);
		goto IL_0045;
	}

IL_0044:
	{
		G_B4_0 = 1;
	}

IL_0045:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20318));
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0064;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20319));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2348>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20320));
		float* L_14 = ___0_dptr;
		int32_t L_15 = V_1;
		uint32_t L_16 = sizeof(float);
		float* L_17 = V_4;
		float L_18 = (*(float*)L_17);
		*(float*)((float*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), (int32_t)L_16)))) = L_18;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20321));
	}

IL_0064:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20322));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20323));
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0069:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20324));
		int32_t L_20 = V_1;
		int32_t L_21 = ___4_n;
		V_6 = (bool)((((int32_t)L_20) < ((int32_t)L_21))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20325));
		bool L_22 = V_6;
		if (L_22)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20326));
		return;
	}
}
// Method Definition Index: 116728
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_m78BBC4DBE234DA027814A059C7A569C168B14265_gshared (Il2CppFullySharedGenericStruct* ___0_dptr, void* ___1_base_addr, int32_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, Il2CppFullySharedGenericStruct* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	void* L_12 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	const uint32_t SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 5));
	const Il2CppFullySharedGenericStruct L_19 = alloca(SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314);
	const Il2CppFullySharedGenericStruct L_11 = alloca(SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
	Il2CppFullySharedGenericStruct V_0 = alloca(SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
	memset(V_0, 0, SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	Il2CppFullySharedGenericStruct* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, V_0, (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20327));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20328));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20329));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20330));
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_0, SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20331));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20332));
		goto IL_006a;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20333));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20334));
		int32_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int32_t L_2 = (*(((int32_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 4))))));
		V_2 = ((int64_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2360>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20335));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20336));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (Il2CppFullySharedGenericStruct*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2362>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20337));
		Il2CppFullySharedGenericStruct* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0045;
		}
	}
	{
		Il2CppFullySharedGenericStruct* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594;
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_U_tD3AAA6C44816F6B7C2E20A7D231588A6DD300594);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		int32_t L_13;
		L_13 = ConstrainedFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 3), L_12, (void*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20338));
		G_B4_0 = ((((int32_t)L_13) < ((int32_t)0))? 1 : 0);
		goto IL_0046;
	}

IL_0045:
	{
		G_B4_0 = 1;
	}

IL_0046:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20339));
		bool L_14 = V_5;
		if (!L_14)
		{
			goto IL_0065;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20340));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20341));
		Il2CppFullySharedGenericStruct* L_15 = ___0_dptr;
		int32_t L_16 = V_1;
		uint32_t L_17 = SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314;
		Il2CppFullySharedGenericStruct* L_18 = V_4;
		il2cpp_codegen_memcpy(L_19, L_18, SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_16), (int32_t)L_17)))), L_19, SizeOf_T_t7746E565CB09ADDE66D7FE8BA2706651748F4314);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 5), (void**)(Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_16), (int32_t)L_17)))), (void*)L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20342));
	}

IL_0065:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20344));
		int32_t L_20 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_006a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2357>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20345));
		int32_t L_21 = V_1;
		int32_t L_22 = ___4_n;
		V_6 = (bool)((((int32_t)L_21) < ((int32_t)L_22))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20346));
		bool L_23 = V_6;
		if (L_23)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20347));
		return;
	}
}
// Method Definition Index: 116727
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Avx2_EmulatedGather_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_m93179BB5AA8A484650210DDAA1EB8D4319DE5686_gshared (Il2CppFullySharedGenericStruct* ___0_dptr, void* ___1_base_addr, int64_t* ___2_indexPtr, int32_t ___3_scale, int32_t ___4_n, Il2CppFullySharedGenericStruct* ___5_mask, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	void* L_12 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	const uint32_t SizeOf_T_t2BE133648A5E32C27FC46CF83B739F6CD3C673A8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 5));
	const Il2CppFullySharedGenericStruct L_19 = alloca(SizeOf_T_t2BE133648A5E32C27FC46CF83B739F6CD3C673A8);
	const Il2CppFullySharedGenericStruct L_11 = alloca(SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747);
	Il2CppFullySharedGenericStruct V_0 = alloca(SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747);
	memset(V_0, 0, SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747);
	int32_t V_1 = 0;
	int64_t V_2 = 0;
	int64_t V_3 = 0;
	Il2CppFullySharedGenericStruct* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_dptr), (&___1_base_addr), (&___2_indexPtr), (&___3_scale), (&___4_n), (&___5_mask));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, V_0, (&V_1), (&V_2), (&V_3), (&V_4));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20306));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 20307));
	int32_t G_B4_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20308));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2339>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20309));
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_0, SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20310));
		V_1 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20311));
		goto IL_0069;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20312));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20313));
		int64_t* L_0 = ___2_indexPtr;
		int32_t L_1 = V_1;
		int64_t L_2 = (*(((int64_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), 8))))));
		V_2 = L_2;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2344>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20314));
		int64_t L_3 = V_2;
		int32_t L_4 = ___3_scale;
		V_3 = ((int64_t)il2cpp_codegen_multiply(L_3, ((int64_t)L_4)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2345>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20315));
		void* L_5 = ___1_base_addr;
		int64_t L_6 = V_3;
		V_4 = (Il2CppFullySharedGenericStruct*)((void*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)L_6)));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20316));
		Il2CppFullySharedGenericStruct* L_7 = ___5_mask;
		if ((((intptr_t)L_7) == ((intptr_t)((uintptr_t)0))))
		{
			goto IL_0044;
		}
	}
	{
		Il2CppFullySharedGenericStruct* L_8 = ___5_mask;
		int32_t L_9 = V_1;
		uint32_t L_10 = SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747;
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_U_t64249877289BCA4A66FB09171AC3649960014747);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		int32_t L_13;
		L_13 = ConstrainedFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 3), L_12, (void*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_9), (int32_t)L_10)))), L_11);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20317));
		G_B4_0 = ((((int32_t)L_13) < ((int32_t)0))? 1 : 0);
		goto IL_0045;
	}

IL_0044:
	{
		G_B4_0 = 1;
	}

IL_0045:
	{
		V_5 = (bool)G_B4_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20318));
		bool L_14 = V_5;
		if (!L_14)
		{
			goto IL_0064;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20319));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2348>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20320));
		Il2CppFullySharedGenericStruct* L_15 = ___0_dptr;
		int32_t L_16 = V_1;
		uint32_t L_17 = SizeOf_T_t2BE133648A5E32C27FC46CF83B739F6CD3C673A8;
		Il2CppFullySharedGenericStruct* L_18 = V_4;
		il2cpp_codegen_memcpy(L_19, L_18, SizeOf_T_t2BE133648A5E32C27FC46CF83B739F6CD3C673A8);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_16), (int32_t)L_17)))), L_19, SizeOf_T_t2BE133648A5E32C27FC46CF83B739F6CD3C673A8);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 5), (void**)(Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_15, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_16), (int32_t)L_17)))), (void*)L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20321));
	}

IL_0064:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20322));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20323));
		int32_t L_20 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0069:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2341>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20324));
		int32_t L_21 = V_1;
		int32_t L_22 = ___4_n;
		V_6 = (bool)((((int32_t)L_21) < ((int32_t)L_22))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20325));
		bool L_23 = V_6;
		if (L_23)
		{
			goto IL_000d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Avx2.cs:2351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 20326));
		return;
	}
}
// Method Definition Index: 117202
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	uint8_t V_7 = 0x0;
	bool V_8 = false;
	uint8_t V_9 = 0x0;
	bool V_10 = false;
	bool V_11 = false;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	bool V_21 = false;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	bool V_27 = false;
	bool V_28 = false;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	bool V_31 = false;
	bool V_32 = false;
	bool V_33 = false;
	bool V_34 = false;
	bool V_35 = false;
	int32_t V_36 = 0;
	bool V_37 = false;
	bool V_38 = false;
	bool V_39 = false;
	bool V_40 = false;
	bool V_41 = false;
	bool V_42 = false;
	uint8_t V_43 = 0x0;
	bool V_44 = false;
	bool V_45 = false;
	int32_t V_46 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_5), (&V_6), (&V_7), (&V_9), (&V_10), (&V_36));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25436));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25437));
	int32_t G_B13_0 = 0;
	int32_t G_B26_0 = 0;
	int32_t G_B36_0 = 0;
	int32_t G_B46_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B62_0 = 0;
	int32_t G_B62_1 = 0;
	int32_t G_B71_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B72_0 = 0;
	int32_t G_B73_0 = 0;
	int32_t G_B73_1 = 0;
	int32_t G_B81_0 = 0;
	int32_t G_B80_0 = 0;
	int32_t G_B82_0 = 0;
	int32_t G_B82_1 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25438));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25439));
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25440));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25441));
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25442));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25443));
		goto IL_01ea;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25444));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25445));
		uint8_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(uint8_t);
		uint8_t L_3 = (*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25446));
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		V_8 = (bool)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25447));
		bool L_6 = V_8;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25448));
		V_0 = (bool)1;
	}

IL_0033:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25449));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25450));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25451));
		goto IL_01d6;
	}

IL_003d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25452));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25453));
		uint8_t* L_7 = ___2_b;
		int32_t L_8 = V_4;
		uint32_t L_9 = sizeof(uint8_t);
		uint8_t L_10 = (*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))));
		V_9 = L_10;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25454));
		int32_t L_11 = V_4;
		int32_t L_12 = ___3_blen;
		V_11 = (bool)((((int32_t)L_11) == ((int32_t)L_12))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25455));
		bool L_13 = V_11;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25456));
		V_1 = (bool)1;
	}

IL_005e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25457));
		int32_t L_14 = ___5_imm8;
		V_13 = ((int32_t)(((int32_t)(L_14>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25458));
		int32_t L_15 = V_13;
		V_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25459));
		int32_t L_16 = V_12;
		switch (L_16)
		{
			case 0:
			{
				goto IL_0082;
			}
			case 1:
			{
				goto IL_00c9;
			}
			case 2:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_017e;
	}

IL_0082:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25460));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_17;
		L_17 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		uint8_t L_18 = V_7;
		uint8_t L_19 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		NullCheck(L_17);
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_17, L_18, L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		V_10 = L_20;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25463));
		bool L_21 = V_0;
		bool L_22 = V_1;
		V_14 = (bool)((int32_t)(((((int32_t)L_21) == ((int32_t)0))? 1 : 0)&(int32_t)L_22));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25464));
		bool L_23 = V_14;
		if (!L_23)
		{
			goto IL_00a3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25465));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25466));
		goto IL_00c4;
	}

IL_00a3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25467));
		bool L_24 = V_0;
		if (!L_24)
		{
			goto IL_00ac;
		}
	}
	{
		bool L_25 = V_1;
		G_B13_0 = ((((int32_t)L_25) == ((int32_t)0))? 1 : 0);
		goto IL_00ad;
	}

IL_00ac:
	{
		G_B13_0 = 0;
	}

IL_00ad:
	{
		V_15 = (bool)G_B13_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25468));
		bool L_26 = V_15;
		if (!L_26)
		{
			goto IL_00b8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25469));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25470));
		goto IL_00c4;
	}

IL_00b8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25471));
		bool L_27 = V_0;
		bool L_28 = V_1;
		V_16 = (bool)((int32_t)((int32_t)L_27&(int32_t)L_28));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25472));
		bool L_29 = V_16;
		if (!L_29)
		{
			goto IL_00c4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25473));
		V_10 = (bool)0;
	}

IL_00c4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25474));
		goto IL_01c2;
	}

IL_00c9:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25475));
		int32_t L_30 = V_3;
		V_17 = (bool)((((int32_t)((int32_t)(L_30&1))) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25476));
		bool L_31 = V_17;
		if (!L_31)
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25477));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30* L_32;
		L_32 = Comparer_1_get_Default_m84FF70BAB6A30BC2A0EABE8B0E58FCBD8F40C8FB(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		uint8_t L_33 = V_9;
		uint8_t L_34 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		NullCheck(L_32);
		int32_t L_35;
		L_35 = VirtualFuncInvoker2< int32_t, uint8_t, uint8_t >::Invoke(6, L_32, L_33, L_34);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		V_10 = (bool)((((int32_t)((((int32_t)L_35) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25480));
		goto IL_0103;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25481));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		Comparer_1_t49F23FD0F51B7B3F17D30558E0A425107523CC30* L_36;
		L_36 = Comparer_1_get_Default_m84FF70BAB6A30BC2A0EABE8B0E58FCBD8F40C8FB(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		uint8_t L_37 = V_9;
		uint8_t L_38 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		NullCheck(L_36);
		int32_t L_39;
		L_39 = VirtualFuncInvoker2< int32_t, uint8_t, uint8_t >::Invoke(6, L_36, L_37, L_38);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		V_10 = (bool)((((int32_t)((((int32_t)L_39) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0103:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25484));
		bool L_40 = V_0;
		bool L_41 = V_1;
		V_18 = (bool)((int32_t)(((((int32_t)L_40) == ((int32_t)0))? 1 : 0)&(int32_t)L_41));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25485));
		bool L_42 = V_18;
		if (!L_42)
		{
			goto IL_0114;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25486));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25487));
		goto IL_0135;
	}

IL_0114:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25488));
		bool L_43 = V_0;
		if (!L_43)
		{
			goto IL_011d;
		}
	}
	{
		bool L_44 = V_1;
		G_B26_0 = ((((int32_t)L_44) == ((int32_t)0))? 1 : 0);
		goto IL_011e;
	}

IL_011d:
	{
		G_B26_0 = 0;
	}

IL_011e:
	{
		V_19 = (bool)G_B26_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25489));
		bool L_45 = V_19;
		if (!L_45)
		{
			goto IL_0129;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25490));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25491));
		goto IL_0135;
	}

IL_0129:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25492));
		bool L_46 = V_0;
		bool L_47 = V_1;
		V_20 = (bool)((int32_t)((int32_t)L_46&(int32_t)L_47));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25493));
		bool L_48 = V_20;
		if (!L_48)
		{
			goto IL_0135;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25494));
		V_10 = (bool)0;
	}

IL_0135:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25495));
		goto IL_01c2;
	}

IL_013a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25496));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_49;
		L_49 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		uint8_t L_50 = V_7;
		uint8_t L_51 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_49, L_50, L_51);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		V_10 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25499));
		bool L_53 = V_0;
		bool L_54 = V_1;
		V_21 = (bool)((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25500));
		bool L_55 = V_21;
		if (!L_55)
		{
			goto IL_015b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25501));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25502));
		goto IL_017c;
	}

IL_015b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25503));
		bool L_56 = V_0;
		if (!L_56)
		{
			goto IL_0164;
		}
	}
	{
		bool L_57 = V_1;
		G_B36_0 = ((((int32_t)L_57) == ((int32_t)0))? 1 : 0);
		goto IL_0165;
	}

IL_0164:
	{
		G_B36_0 = 0;
	}

IL_0165:
	{
		V_22 = (bool)G_B36_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25504));
		bool L_58 = V_22;
		if (!L_58)
		{
			goto IL_0170;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25505));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25506));
		goto IL_017c;
	}

IL_0170:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25507));
		bool L_59 = V_0;
		bool L_60 = V_1;
		V_23 = (bool)((int32_t)((int32_t)L_59&(int32_t)L_60));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25508));
		bool L_61 = V_23;
		if (!L_61)
		{
			goto IL_017c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25509));
		V_10 = (bool)1;
	}

IL_017c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25510));
		goto IL_01c2;
	}

IL_017e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25511));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_62;
		L_62 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		uint8_t L_63 = V_7;
		uint8_t L_64 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		NullCheck(L_62);
		bool L_65;
		L_65 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_62, L_63, L_64);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		V_10 = L_65;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25514));
		bool L_66 = V_0;
		bool L_67 = V_1;
		V_24 = (bool)((int32_t)(((((int32_t)L_66) == ((int32_t)0))? 1 : 0)&(int32_t)L_67));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25515));
		bool L_68 = V_24;
		if (!L_68)
		{
			goto IL_019f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25516));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25517));
		goto IL_01c0;
	}

IL_019f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25518));
		bool L_69 = V_0;
		if (!L_69)
		{
			goto IL_01a8;
		}
	}
	{
		bool L_70 = V_1;
		G_B46_0 = ((((int32_t)L_70) == ((int32_t)0))? 1 : 0);
		goto IL_01a9;
	}

IL_01a8:
	{
		G_B46_0 = 0;
	}

IL_01a9:
	{
		V_25 = (bool)G_B46_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25519));
		bool L_71 = V_25;
		if (!L_71)
		{
			goto IL_01b4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25520));
		V_10 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25521));
		goto IL_01c0;
	}

IL_01b4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25522));
		bool L_72 = V_0;
		bool L_73 = V_1;
		V_26 = (bool)((int32_t)((int32_t)L_72&(int32_t)L_73));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25523));
		bool L_74 = V_26;
		if (!L_74)
		{
			goto IL_01c0;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25524));
		V_10 = (bool)1;
	}

IL_01c0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:287>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25525));
		goto IL_01c2;
	}

IL_01c2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25526));
		int32_t L_75 = V_3;
		int32_t L_76 = V_4;
		bool L_77 = V_10;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_75, L_76, L_77, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25528));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25529));
		int32_t L_78 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01d6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25530));
		int32_t L_79 = V_4;
		int32_t L_80 = ___4_len;
		V_27 = (bool)((((int32_t)L_79) < ((int32_t)L_80))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25531));
		bool L_81 = V_27;
		if (L_81)
		{
			goto IL_003d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25532));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25533));
		int32_t L_82 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_82, 1));
	}

IL_01ea:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25534));
		int32_t L_83 = V_3;
		int32_t L_84 = ___4_len;
		V_28 = (bool)((((int32_t)L_83) < ((int32_t)L_84))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25535));
		bool L_85 = V_28;
		if (L_85)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25536));
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25537));
		int32_t L_86 = ___5_imm8;
		V_30 = ((int32_t)(((int32_t)(L_86>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25538));
		int32_t L_87 = V_30;
		V_29 = L_87;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25539));
		int32_t L_88 = V_29;
		switch (L_88)
		{
			case 0:
			{
				goto IL_0223;
			}
			case 1:
			{
				goto IL_0270;
			}
			case 2:
			{
				goto IL_02cb;
			}
			case 3:
			{
				goto IL_02fb;
			}
		}
	}
	{
		goto IL_035a;
	}

IL_0223:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25540));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25541));
		goto IL_0260;
	}

IL_0227:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25542));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25543));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25544));
		goto IL_024f;
	}

IL_022d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25545));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25546));
		int32_t L_89 = V_6;
		int32_t L_90 = V_4;
		int32_t L_91 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		bool L_92;
		L_92 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_90, L_91, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		if (L_92)
		{
			G_B61_0 = L_89;
			goto IL_023f;
		}
		G_B60_0 = L_89;
	}
	{
		G_B62_0 = 0;
		G_B62_1 = G_B60_0;
		goto IL_0240;
	}

IL_023f:
	{
		G_B62_0 = 1;
		G_B62_1 = G_B61_0;
	}

IL_0240:
	{
		int32_t L_93 = V_3;
		V_6 = ((int32_t)(G_B62_1|((int32_t)(G_B62_0<<((int32_t)(L_93&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25548));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25549));
		int32_t L_94 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_94, 1));
	}

IL_024f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25550));
		int32_t L_95 = V_4;
		int32_t L_96 = ___4_len;
		V_31 = (bool)((((int32_t)L_95) < ((int32_t)L_96))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25551));
		bool L_97 = V_31;
		if (L_97)
		{
			goto IL_022d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25552));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25553));
		int32_t L_98 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_98, 1));
	}

IL_0260:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25554));
		int32_t L_99 = V_3;
		int32_t L_100 = ___4_len;
		V_32 = (bool)((((int32_t)L_99) < ((int32_t)L_100))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25555));
		bool L_101 = V_32;
		if (L_101)
		{
			goto IL_0227;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25556));
		goto IL_035a;
	}

IL_0270:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25557));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25558));
		goto IL_02bb;
	}

IL_0274:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25559));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25560));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25561));
		goto IL_02aa;
	}

IL_027a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25562));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25563));
		int32_t L_102 = V_6;
		int32_t L_103 = V_4;
		int32_t L_104 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		bool L_105;
		L_105 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_103, L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		if (!L_105)
		{
			G_B71_0 = L_102;
			goto IL_0297;
		}
		G_B70_0 = L_102;
	}
	{
		int32_t L_106 = V_4;
		int32_t L_107 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		bool L_108;
		L_108 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_106, 1)), L_107, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		if (L_108)
		{
			G_B72_0 = G_B70_0;
			goto IL_029a;
		}
		G_B71_0 = G_B70_0;
	}

IL_0297:
	{
		G_B73_0 = 0;
		G_B73_1 = G_B71_0;
		goto IL_029b;
	}

IL_029a:
	{
		G_B73_0 = 1;
		G_B73_1 = G_B72_0;
	}

IL_029b:
	{
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(G_B73_1|((int32_t)(G_B73_0<<((int32_t)(L_109&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25566));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25567));
		int32_t L_110 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_110, 2));
	}

IL_02aa:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25568));
		int32_t L_111 = V_4;
		int32_t L_112 = ___4_len;
		V_33 = (bool)((((int32_t)L_111) < ((int32_t)L_112))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25569));
		bool L_113 = V_33;
		if (L_113)
		{
			goto IL_027a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25570));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25571));
		int32_t L_114 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_114, 1));
	}

IL_02bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25572));
		int32_t L_115 = V_3;
		int32_t L_116 = ___4_len;
		V_34 = (bool)((((int32_t)L_115) < ((int32_t)L_116))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25573));
		bool L_117 = V_34;
		if (L_117)
		{
			goto IL_0274;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25574));
		goto IL_035a;
	}

IL_02cb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25575));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25576));
		goto IL_02ee;
	}

IL_02cf:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25577));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25578));
		int32_t L_118 = V_6;
		int32_t L_119 = V_3;
		int32_t L_120 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		bool L_121;
		L_121 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_119, L_120, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		if (L_121)
		{
			G_B81_0 = L_118;
			goto IL_02e0;
		}
		G_B80_0 = L_118;
	}
	{
		G_B82_0 = 0;
		G_B82_1 = G_B80_0;
		goto IL_02e1;
	}

IL_02e0:
	{
		G_B82_0 = 1;
		G_B82_1 = G_B81_0;
	}

IL_02e1:
	{
		int32_t L_122 = V_3;
		V_6 = ((int32_t)(G_B82_1|((int32_t)(G_B82_0<<((int32_t)(L_122&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25580));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25581));
		int32_t L_123 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_123, 1));
	}

IL_02ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25582));
		int32_t L_124 = V_3;
		int32_t L_125 = ___4_len;
		V_35 = (bool)((((int32_t)L_124) < ((int32_t)L_125))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25583));
		bool L_126 = V_35;
		if (L_126)
		{
			goto IL_02cf;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25584));
		goto IL_035a;
	}

IL_02fb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25585));
		int32_t L_127 = ___6_allOnes;
		V_6 = L_127;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25586));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25587));
		goto IL_034d;
	}

IL_0303:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25588));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25589));
		int32_t L_128 = V_3;
		V_36 = L_128;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25590));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25591));
		goto IL_033a;
	}

IL_030c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25592));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25593));
		int32_t L_129 = V_4;
		int32_t L_130 = V_36;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		bool L_131;
		L_131 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_129, L_130, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		V_37 = (bool)((((int32_t)L_131) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25595));
		bool L_132 = V_37;
		if (!L_132)
		{
			goto IL_032d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25596));
		int32_t L_133 = V_6;
		int32_t L_134 = V_3;
		V_6 = ((int32_t)(L_133&((~((int32_t)(1<<((int32_t)(L_134&((int32_t)31)))))))));
	}

IL_032d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25597));
		int32_t L_135 = V_36;
		V_36 = ((int32_t)il2cpp_codegen_add(L_135, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25598));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25599));
		int32_t L_136 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_136, 1));
	}

IL_033a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25600));
		int32_t L_137 = V_4;
		int32_t L_138 = ___4_len;
		int32_t L_139 = V_3;
		V_38 = (bool)((((int32_t)L_137) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_138, L_139))))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25601));
		bool L_140 = V_38;
		if (L_140)
		{
			goto IL_030c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25602));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25603));
		int32_t L_141 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_141, 1));
	}

IL_034d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25604));
		int32_t L_142 = V_3;
		int32_t L_143 = ___4_len;
		V_39 = (bool)((((int32_t)L_142) < ((int32_t)L_143))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25605));
		bool L_144 = V_39;
		if (L_144)
		{
			goto IL_0303;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:340>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25606));
		goto IL_035a;
	}

IL_035a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25607));
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25608));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25609));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25610));
		goto IL_0401;
	}

IL_0366:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25611));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25612));
		int32_t L_145 = ___5_imm8;
		V_40 = (bool)((!(((uint32_t)((int32_t)(L_145&((int32_t)16)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25613));
		bool L_146 = V_40;
		if (!L_146)
		{
			goto IL_03ee;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25614));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25615));
		int32_t L_147 = ___5_imm8;
		V_41 = (bool)((!(((uint32_t)((int32_t)(L_147&((int32_t)32)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25616));
		bool L_148 = V_41;
		if (!L_148)
		{
			goto IL_03dc;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25617));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25618));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_149;
		L_149 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		uint8_t* L_150 = ___2_b;
		int32_t L_151 = V_3;
		uint32_t L_152 = sizeof(uint8_t);
		uint8_t L_153 = (*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_150, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_151), (int32_t)L_152)))));
		il2cpp_codegen_initobj((&V_43), sizeof(uint8_t));
		uint8_t L_154 = V_43;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		NullCheck(L_149);
		bool L_155;
		L_155 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_149, L_153, L_154);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		V_42 = L_155;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25621));
		bool L_156 = V_42;
		if (!L_156)
		{
			goto IL_03b3;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25622));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25623));
		V_1 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25624));
	}

IL_03b3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25625));
		bool L_157 = V_1;
		V_44 = L_157;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25626));
		bool L_158 = V_44;
		if (!L_158)
		{
			goto IL_03ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25627));
		int32_t L_159 = V_5;
		int32_t L_160 = V_6;
		int32_t L_161 = V_3;
		V_5 = ((int32_t)(L_159|((int32_t)(L_160&((int32_t)(1<<((int32_t)(L_161&((int32_t)31)))))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25628));
		goto IL_03d9;
	}

IL_03ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25629));
		int32_t L_162 = V_5;
		int32_t L_163 = V_6;
		int32_t L_164 = V_3;
		V_5 = ((int32_t)(L_162|((int32_t)(((~L_163))&((int32_t)(1<<((int32_t)(L_164&((int32_t)31)))))))));
	}

IL_03d9:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25630));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25631));
		goto IL_03eb;
	}

IL_03dc:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25632));
		int32_t L_165 = V_5;
		int32_t L_166 = V_6;
		int32_t L_167 = V_3;
		V_5 = ((int32_t)(L_165|((int32_t)(((~L_166))&((int32_t)(1<<((int32_t)(L_167&((int32_t)31)))))))));
	}

IL_03eb:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25633));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25634));
		goto IL_03fc;
	}

IL_03ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25635));
		int32_t L_168 = V_5;
		int32_t L_169 = V_6;
		int32_t L_170 = V_3;
		V_5 = ((int32_t)(L_168|((int32_t)(L_169&((int32_t)(1<<((int32_t)(L_170&((int32_t)31)))))))));
	}

IL_03fc:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25636));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25637));
		int32_t L_171 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_171, 1));
	}

IL_0401:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25638));
		int32_t L_172 = V_3;
		int32_t L_173 = ___4_len;
		V_45 = (bool)((((int32_t)L_172) < ((int32_t)L_173))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25639));
		bool L_174 = V_45;
		if (L_174)
		{
			goto IL_0366;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25640));
		int32_t L_175 = V_5;
		V_46 = L_175;
		goto IL_0415;
	}

IL_0415:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25641));
		int32_t L_176 = V_46;
		return L_176;
	}
}
// Method Definition Index: 117202
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int16_t V_7 = 0;
	bool V_8 = false;
	int16_t V_9 = 0;
	bool V_10 = false;
	bool V_11 = false;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	bool V_21 = false;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	bool V_27 = false;
	bool V_28 = false;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	bool V_31 = false;
	bool V_32 = false;
	bool V_33 = false;
	bool V_34 = false;
	bool V_35 = false;
	int32_t V_36 = 0;
	bool V_37 = false;
	bool V_38 = false;
	bool V_39 = false;
	bool V_40 = false;
	bool V_41 = false;
	bool V_42 = false;
	int16_t V_43 = 0;
	bool V_44 = false;
	bool V_45 = false;
	int32_t V_46 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_5), (&V_6), (&V_7), (&V_9), (&V_10), (&V_36));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25436));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25437));
	int32_t G_B13_0 = 0;
	int32_t G_B26_0 = 0;
	int32_t G_B36_0 = 0;
	int32_t G_B46_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B62_0 = 0;
	int32_t G_B62_1 = 0;
	int32_t G_B71_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B72_0 = 0;
	int32_t G_B73_0 = 0;
	int32_t G_B73_1 = 0;
	int32_t G_B81_0 = 0;
	int32_t G_B80_0 = 0;
	int32_t G_B82_0 = 0;
	int32_t G_B82_1 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25438));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25439));
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25440));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25441));
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25442));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25443));
		goto IL_01ea;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25444));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25445));
		int16_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(int16_t);
		int16_t L_3 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25446));
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		V_8 = (bool)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25447));
		bool L_6 = V_8;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25448));
		V_0 = (bool)1;
	}

IL_0033:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25449));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25450));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25451));
		goto IL_01d6;
	}

IL_003d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25452));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25453));
		int16_t* L_7 = ___2_b;
		int32_t L_8 = V_4;
		uint32_t L_9 = sizeof(int16_t);
		int16_t L_10 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))));
		V_9 = L_10;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25454));
		int32_t L_11 = V_4;
		int32_t L_12 = ___3_blen;
		V_11 = (bool)((((int32_t)L_11) == ((int32_t)L_12))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25455));
		bool L_13 = V_11;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25456));
		V_1 = (bool)1;
	}

IL_005e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25457));
		int32_t L_14 = ___5_imm8;
		V_13 = ((int32_t)(((int32_t)(L_14>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25458));
		int32_t L_15 = V_13;
		V_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25459));
		int32_t L_16 = V_12;
		switch (L_16)
		{
			case 0:
			{
				goto IL_0082;
			}
			case 1:
			{
				goto IL_00c9;
			}
			case 2:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_017e;
	}

IL_0082:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25460));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_17;
		L_17 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		int16_t L_18 = V_7;
		int16_t L_19 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		NullCheck(L_17);
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_17, L_18, L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		V_10 = L_20;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25463));
		bool L_21 = V_0;
		bool L_22 = V_1;
		V_14 = (bool)((int32_t)(((((int32_t)L_21) == ((int32_t)0))? 1 : 0)&(int32_t)L_22));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25464));
		bool L_23 = V_14;
		if (!L_23)
		{
			goto IL_00a3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25465));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25466));
		goto IL_00c4;
	}

IL_00a3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25467));
		bool L_24 = V_0;
		if (!L_24)
		{
			goto IL_00ac;
		}
	}
	{
		bool L_25 = V_1;
		G_B13_0 = ((((int32_t)L_25) == ((int32_t)0))? 1 : 0);
		goto IL_00ad;
	}

IL_00ac:
	{
		G_B13_0 = 0;
	}

IL_00ad:
	{
		V_15 = (bool)G_B13_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25468));
		bool L_26 = V_15;
		if (!L_26)
		{
			goto IL_00b8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25469));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25470));
		goto IL_00c4;
	}

IL_00b8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25471));
		bool L_27 = V_0;
		bool L_28 = V_1;
		V_16 = (bool)((int32_t)((int32_t)L_27&(int32_t)L_28));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25472));
		bool L_29 = V_16;
		if (!L_29)
		{
			goto IL_00c4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25473));
		V_10 = (bool)0;
	}

IL_00c4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25474));
		goto IL_01c2;
	}

IL_00c9:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25475));
		int32_t L_30 = V_3;
		V_17 = (bool)((((int32_t)((int32_t)(L_30&1))) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25476));
		bool L_31 = V_17;
		if (!L_31)
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25477));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* L_32;
		L_32 = Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		int16_t L_33 = V_9;
		int16_t L_34 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		NullCheck(L_32);
		int32_t L_35;
		L_35 = VirtualFuncInvoker2< int32_t, int16_t, int16_t >::Invoke(6, L_32, L_33, L_34);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		V_10 = (bool)((((int32_t)((((int32_t)L_35) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25480));
		goto IL_0103;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25481));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		Comparer_1_t7EDCB50F141B8333E02C67781CAC2D41381F0563* L_36;
		L_36 = Comparer_1_get_Default_mE45154132033749FD101CB1689E0375B42C4B407(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		int16_t L_37 = V_9;
		int16_t L_38 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		NullCheck(L_36);
		int32_t L_39;
		L_39 = VirtualFuncInvoker2< int32_t, int16_t, int16_t >::Invoke(6, L_36, L_37, L_38);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		V_10 = (bool)((((int32_t)((((int32_t)L_39) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0103:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25484));
		bool L_40 = V_0;
		bool L_41 = V_1;
		V_18 = (bool)((int32_t)(((((int32_t)L_40) == ((int32_t)0))? 1 : 0)&(int32_t)L_41));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25485));
		bool L_42 = V_18;
		if (!L_42)
		{
			goto IL_0114;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25486));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25487));
		goto IL_0135;
	}

IL_0114:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25488));
		bool L_43 = V_0;
		if (!L_43)
		{
			goto IL_011d;
		}
	}
	{
		bool L_44 = V_1;
		G_B26_0 = ((((int32_t)L_44) == ((int32_t)0))? 1 : 0);
		goto IL_011e;
	}

IL_011d:
	{
		G_B26_0 = 0;
	}

IL_011e:
	{
		V_19 = (bool)G_B26_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25489));
		bool L_45 = V_19;
		if (!L_45)
		{
			goto IL_0129;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25490));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25491));
		goto IL_0135;
	}

IL_0129:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25492));
		bool L_46 = V_0;
		bool L_47 = V_1;
		V_20 = (bool)((int32_t)((int32_t)L_46&(int32_t)L_47));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25493));
		bool L_48 = V_20;
		if (!L_48)
		{
			goto IL_0135;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25494));
		V_10 = (bool)0;
	}

IL_0135:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25495));
		goto IL_01c2;
	}

IL_013a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25496));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_49;
		L_49 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		int16_t L_50 = V_7;
		int16_t L_51 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_49, L_50, L_51);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		V_10 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25499));
		bool L_53 = V_0;
		bool L_54 = V_1;
		V_21 = (bool)((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25500));
		bool L_55 = V_21;
		if (!L_55)
		{
			goto IL_015b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25501));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25502));
		goto IL_017c;
	}

IL_015b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25503));
		bool L_56 = V_0;
		if (!L_56)
		{
			goto IL_0164;
		}
	}
	{
		bool L_57 = V_1;
		G_B36_0 = ((((int32_t)L_57) == ((int32_t)0))? 1 : 0);
		goto IL_0165;
	}

IL_0164:
	{
		G_B36_0 = 0;
	}

IL_0165:
	{
		V_22 = (bool)G_B36_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25504));
		bool L_58 = V_22;
		if (!L_58)
		{
			goto IL_0170;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25505));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25506));
		goto IL_017c;
	}

IL_0170:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25507));
		bool L_59 = V_0;
		bool L_60 = V_1;
		V_23 = (bool)((int32_t)((int32_t)L_59&(int32_t)L_60));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25508));
		bool L_61 = V_23;
		if (!L_61)
		{
			goto IL_017c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25509));
		V_10 = (bool)1;
	}

IL_017c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25510));
		goto IL_01c2;
	}

IL_017e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25511));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_62;
		L_62 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		int16_t L_63 = V_7;
		int16_t L_64 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		NullCheck(L_62);
		bool L_65;
		L_65 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_62, L_63, L_64);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		V_10 = L_65;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25514));
		bool L_66 = V_0;
		bool L_67 = V_1;
		V_24 = (bool)((int32_t)(((((int32_t)L_66) == ((int32_t)0))? 1 : 0)&(int32_t)L_67));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25515));
		bool L_68 = V_24;
		if (!L_68)
		{
			goto IL_019f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25516));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25517));
		goto IL_01c0;
	}

IL_019f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25518));
		bool L_69 = V_0;
		if (!L_69)
		{
			goto IL_01a8;
		}
	}
	{
		bool L_70 = V_1;
		G_B46_0 = ((((int32_t)L_70) == ((int32_t)0))? 1 : 0);
		goto IL_01a9;
	}

IL_01a8:
	{
		G_B46_0 = 0;
	}

IL_01a9:
	{
		V_25 = (bool)G_B46_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25519));
		bool L_71 = V_25;
		if (!L_71)
		{
			goto IL_01b4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25520));
		V_10 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25521));
		goto IL_01c0;
	}

IL_01b4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25522));
		bool L_72 = V_0;
		bool L_73 = V_1;
		V_26 = (bool)((int32_t)((int32_t)L_72&(int32_t)L_73));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25523));
		bool L_74 = V_26;
		if (!L_74)
		{
			goto IL_01c0;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25524));
		V_10 = (bool)1;
	}

IL_01c0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:287>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25525));
		goto IL_01c2;
	}

IL_01c2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25526));
		int32_t L_75 = V_3;
		int32_t L_76 = V_4;
		bool L_77 = V_10;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_75, L_76, L_77, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25528));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25529));
		int32_t L_78 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01d6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25530));
		int32_t L_79 = V_4;
		int32_t L_80 = ___4_len;
		V_27 = (bool)((((int32_t)L_79) < ((int32_t)L_80))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25531));
		bool L_81 = V_27;
		if (L_81)
		{
			goto IL_003d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25532));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25533));
		int32_t L_82 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_82, 1));
	}

IL_01ea:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25534));
		int32_t L_83 = V_3;
		int32_t L_84 = ___4_len;
		V_28 = (bool)((((int32_t)L_83) < ((int32_t)L_84))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25535));
		bool L_85 = V_28;
		if (L_85)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25536));
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25537));
		int32_t L_86 = ___5_imm8;
		V_30 = ((int32_t)(((int32_t)(L_86>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25538));
		int32_t L_87 = V_30;
		V_29 = L_87;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25539));
		int32_t L_88 = V_29;
		switch (L_88)
		{
			case 0:
			{
				goto IL_0223;
			}
			case 1:
			{
				goto IL_0270;
			}
			case 2:
			{
				goto IL_02cb;
			}
			case 3:
			{
				goto IL_02fb;
			}
		}
	}
	{
		goto IL_035a;
	}

IL_0223:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25540));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25541));
		goto IL_0260;
	}

IL_0227:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25542));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25543));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25544));
		goto IL_024f;
	}

IL_022d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25545));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25546));
		int32_t L_89 = V_6;
		int32_t L_90 = V_4;
		int32_t L_91 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		bool L_92;
		L_92 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_90, L_91, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		if (L_92)
		{
			G_B61_0 = L_89;
			goto IL_023f;
		}
		G_B60_0 = L_89;
	}
	{
		G_B62_0 = 0;
		G_B62_1 = G_B60_0;
		goto IL_0240;
	}

IL_023f:
	{
		G_B62_0 = 1;
		G_B62_1 = G_B61_0;
	}

IL_0240:
	{
		int32_t L_93 = V_3;
		V_6 = ((int32_t)(G_B62_1|((int32_t)(G_B62_0<<((int32_t)(L_93&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25548));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25549));
		int32_t L_94 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_94, 1));
	}

IL_024f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25550));
		int32_t L_95 = V_4;
		int32_t L_96 = ___4_len;
		V_31 = (bool)((((int32_t)L_95) < ((int32_t)L_96))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25551));
		bool L_97 = V_31;
		if (L_97)
		{
			goto IL_022d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25552));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25553));
		int32_t L_98 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_98, 1));
	}

IL_0260:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25554));
		int32_t L_99 = V_3;
		int32_t L_100 = ___4_len;
		V_32 = (bool)((((int32_t)L_99) < ((int32_t)L_100))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25555));
		bool L_101 = V_32;
		if (L_101)
		{
			goto IL_0227;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25556));
		goto IL_035a;
	}

IL_0270:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25557));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25558));
		goto IL_02bb;
	}

IL_0274:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25559));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25560));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25561));
		goto IL_02aa;
	}

IL_027a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25562));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25563));
		int32_t L_102 = V_6;
		int32_t L_103 = V_4;
		int32_t L_104 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		bool L_105;
		L_105 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_103, L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		if (!L_105)
		{
			G_B71_0 = L_102;
			goto IL_0297;
		}
		G_B70_0 = L_102;
	}
	{
		int32_t L_106 = V_4;
		int32_t L_107 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		bool L_108;
		L_108 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_106, 1)), L_107, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		if (L_108)
		{
			G_B72_0 = G_B70_0;
			goto IL_029a;
		}
		G_B71_0 = G_B70_0;
	}

IL_0297:
	{
		G_B73_0 = 0;
		G_B73_1 = G_B71_0;
		goto IL_029b;
	}

IL_029a:
	{
		G_B73_0 = 1;
		G_B73_1 = G_B72_0;
	}

IL_029b:
	{
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(G_B73_1|((int32_t)(G_B73_0<<((int32_t)(L_109&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25566));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25567));
		int32_t L_110 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_110, 2));
	}

IL_02aa:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25568));
		int32_t L_111 = V_4;
		int32_t L_112 = ___4_len;
		V_33 = (bool)((((int32_t)L_111) < ((int32_t)L_112))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25569));
		bool L_113 = V_33;
		if (L_113)
		{
			goto IL_027a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25570));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25571));
		int32_t L_114 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_114, 1));
	}

IL_02bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25572));
		int32_t L_115 = V_3;
		int32_t L_116 = ___4_len;
		V_34 = (bool)((((int32_t)L_115) < ((int32_t)L_116))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25573));
		bool L_117 = V_34;
		if (L_117)
		{
			goto IL_0274;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25574));
		goto IL_035a;
	}

IL_02cb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25575));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25576));
		goto IL_02ee;
	}

IL_02cf:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25577));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25578));
		int32_t L_118 = V_6;
		int32_t L_119 = V_3;
		int32_t L_120 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		bool L_121;
		L_121 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_119, L_120, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		if (L_121)
		{
			G_B81_0 = L_118;
			goto IL_02e0;
		}
		G_B80_0 = L_118;
	}
	{
		G_B82_0 = 0;
		G_B82_1 = G_B80_0;
		goto IL_02e1;
	}

IL_02e0:
	{
		G_B82_0 = 1;
		G_B82_1 = G_B81_0;
	}

IL_02e1:
	{
		int32_t L_122 = V_3;
		V_6 = ((int32_t)(G_B82_1|((int32_t)(G_B82_0<<((int32_t)(L_122&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25580));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25581));
		int32_t L_123 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_123, 1));
	}

IL_02ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25582));
		int32_t L_124 = V_3;
		int32_t L_125 = ___4_len;
		V_35 = (bool)((((int32_t)L_124) < ((int32_t)L_125))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25583));
		bool L_126 = V_35;
		if (L_126)
		{
			goto IL_02cf;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25584));
		goto IL_035a;
	}

IL_02fb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25585));
		int32_t L_127 = ___6_allOnes;
		V_6 = L_127;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25586));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25587));
		goto IL_034d;
	}

IL_0303:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25588));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25589));
		int32_t L_128 = V_3;
		V_36 = L_128;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25590));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25591));
		goto IL_033a;
	}

IL_030c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25592));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25593));
		int32_t L_129 = V_4;
		int32_t L_130 = V_36;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		bool L_131;
		L_131 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_129, L_130, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		V_37 = (bool)((((int32_t)L_131) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25595));
		bool L_132 = V_37;
		if (!L_132)
		{
			goto IL_032d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25596));
		int32_t L_133 = V_6;
		int32_t L_134 = V_3;
		V_6 = ((int32_t)(L_133&((~((int32_t)(1<<((int32_t)(L_134&((int32_t)31)))))))));
	}

IL_032d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25597));
		int32_t L_135 = V_36;
		V_36 = ((int32_t)il2cpp_codegen_add(L_135, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25598));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25599));
		int32_t L_136 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_136, 1));
	}

IL_033a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25600));
		int32_t L_137 = V_4;
		int32_t L_138 = ___4_len;
		int32_t L_139 = V_3;
		V_38 = (bool)((((int32_t)L_137) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_138, L_139))))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25601));
		bool L_140 = V_38;
		if (L_140)
		{
			goto IL_030c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25602));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25603));
		int32_t L_141 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_141, 1));
	}

IL_034d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25604));
		int32_t L_142 = V_3;
		int32_t L_143 = ___4_len;
		V_39 = (bool)((((int32_t)L_142) < ((int32_t)L_143))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25605));
		bool L_144 = V_39;
		if (L_144)
		{
			goto IL_0303;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:340>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25606));
		goto IL_035a;
	}

IL_035a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25607));
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25608));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25609));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25610));
		goto IL_0401;
	}

IL_0366:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25611));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25612));
		int32_t L_145 = ___5_imm8;
		V_40 = (bool)((!(((uint32_t)((int32_t)(L_145&((int32_t)16)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25613));
		bool L_146 = V_40;
		if (!L_146)
		{
			goto IL_03ee;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25614));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25615));
		int32_t L_147 = ___5_imm8;
		V_41 = (bool)((!(((uint32_t)((int32_t)(L_147&((int32_t)32)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25616));
		bool L_148 = V_41;
		if (!L_148)
		{
			goto IL_03dc;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25617));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25618));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_149;
		L_149 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		int16_t* L_150 = ___2_b;
		int32_t L_151 = V_3;
		uint32_t L_152 = sizeof(int16_t);
		int16_t L_153 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_150, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_151), (int32_t)L_152)))));
		il2cpp_codegen_initobj((&V_43), sizeof(int16_t));
		int16_t L_154 = V_43;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		NullCheck(L_149);
		bool L_155;
		L_155 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_149, L_153, L_154);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		V_42 = L_155;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25621));
		bool L_156 = V_42;
		if (!L_156)
		{
			goto IL_03b3;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25622));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25623));
		V_1 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25624));
	}

IL_03b3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25625));
		bool L_157 = V_1;
		V_44 = L_157;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25626));
		bool L_158 = V_44;
		if (!L_158)
		{
			goto IL_03ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25627));
		int32_t L_159 = V_5;
		int32_t L_160 = V_6;
		int32_t L_161 = V_3;
		V_5 = ((int32_t)(L_159|((int32_t)(L_160&((int32_t)(1<<((int32_t)(L_161&((int32_t)31)))))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25628));
		goto IL_03d9;
	}

IL_03ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25629));
		int32_t L_162 = V_5;
		int32_t L_163 = V_6;
		int32_t L_164 = V_3;
		V_5 = ((int32_t)(L_162|((int32_t)(((~L_163))&((int32_t)(1<<((int32_t)(L_164&((int32_t)31)))))))));
	}

IL_03d9:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25630));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25631));
		goto IL_03eb;
	}

IL_03dc:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25632));
		int32_t L_165 = V_5;
		int32_t L_166 = V_6;
		int32_t L_167 = V_3;
		V_5 = ((int32_t)(L_165|((int32_t)(((~L_166))&((int32_t)(1<<((int32_t)(L_167&((int32_t)31)))))))));
	}

IL_03eb:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25633));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25634));
		goto IL_03fc;
	}

IL_03ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25635));
		int32_t L_168 = V_5;
		int32_t L_169 = V_6;
		int32_t L_170 = V_3;
		V_5 = ((int32_t)(L_168|((int32_t)(L_169&((int32_t)(1<<((int32_t)(L_170&((int32_t)31)))))))));
	}

IL_03fc:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25636));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25637));
		int32_t L_171 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_171, 1));
	}

IL_0401:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25638));
		int32_t L_172 = V_3;
		int32_t L_173 = ___4_len;
		V_45 = (bool)((((int32_t)L_172) < ((int32_t)L_173))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25639));
		bool L_174 = V_45;
		if (L_174)
		{
			goto IL_0366;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25640));
		int32_t L_175 = V_5;
		V_46 = L_175;
		goto IL_0415;
	}

IL_0415:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25641));
		int32_t L_176 = V_46;
		return L_176;
	}
}
// Method Definition Index: 117202
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int8_t V_7 = 0x0;
	bool V_8 = false;
	int8_t V_9 = 0x0;
	bool V_10 = false;
	bool V_11 = false;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	bool V_21 = false;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	bool V_27 = false;
	bool V_28 = false;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	bool V_31 = false;
	bool V_32 = false;
	bool V_33 = false;
	bool V_34 = false;
	bool V_35 = false;
	int32_t V_36 = 0;
	bool V_37 = false;
	bool V_38 = false;
	bool V_39 = false;
	bool V_40 = false;
	bool V_41 = false;
	bool V_42 = false;
	int8_t V_43 = 0x0;
	bool V_44 = false;
	bool V_45 = false;
	int32_t V_46 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_5), (&V_6), (&V_7), (&V_9), (&V_10), (&V_36));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25436));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25437));
	int32_t G_B13_0 = 0;
	int32_t G_B26_0 = 0;
	int32_t G_B36_0 = 0;
	int32_t G_B46_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B62_0 = 0;
	int32_t G_B62_1 = 0;
	int32_t G_B71_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B72_0 = 0;
	int32_t G_B73_0 = 0;
	int32_t G_B73_1 = 0;
	int32_t G_B81_0 = 0;
	int32_t G_B80_0 = 0;
	int32_t G_B82_0 = 0;
	int32_t G_B82_1 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25438));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25439));
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25440));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25441));
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25442));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25443));
		goto IL_01ea;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25444));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25445));
		int8_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(int8_t);
		int8_t L_3 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25446));
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		V_8 = (bool)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25447));
		bool L_6 = V_8;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25448));
		V_0 = (bool)1;
	}

IL_0033:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25449));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25450));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25451));
		goto IL_01d6;
	}

IL_003d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25452));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25453));
		int8_t* L_7 = ___2_b;
		int32_t L_8 = V_4;
		uint32_t L_9 = sizeof(int8_t);
		int8_t L_10 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))));
		V_9 = L_10;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25454));
		int32_t L_11 = V_4;
		int32_t L_12 = ___3_blen;
		V_11 = (bool)((((int32_t)L_11) == ((int32_t)L_12))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25455));
		bool L_13 = V_11;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25456));
		V_1 = (bool)1;
	}

IL_005e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25457));
		int32_t L_14 = ___5_imm8;
		V_13 = ((int32_t)(((int32_t)(L_14>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25458));
		int32_t L_15 = V_13;
		V_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25459));
		int32_t L_16 = V_12;
		switch (L_16)
		{
			case 0:
			{
				goto IL_0082;
			}
			case 1:
			{
				goto IL_00c9;
			}
			case 2:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_017e;
	}

IL_0082:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25460));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_17;
		L_17 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		int8_t L_18 = V_7;
		int8_t L_19 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		NullCheck(L_17);
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_17, L_18, L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		V_10 = L_20;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25463));
		bool L_21 = V_0;
		bool L_22 = V_1;
		V_14 = (bool)((int32_t)(((((int32_t)L_21) == ((int32_t)0))? 1 : 0)&(int32_t)L_22));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25464));
		bool L_23 = V_14;
		if (!L_23)
		{
			goto IL_00a3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25465));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25466));
		goto IL_00c4;
	}

IL_00a3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25467));
		bool L_24 = V_0;
		if (!L_24)
		{
			goto IL_00ac;
		}
	}
	{
		bool L_25 = V_1;
		G_B13_0 = ((((int32_t)L_25) == ((int32_t)0))? 1 : 0);
		goto IL_00ad;
	}

IL_00ac:
	{
		G_B13_0 = 0;
	}

IL_00ad:
	{
		V_15 = (bool)G_B13_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25468));
		bool L_26 = V_15;
		if (!L_26)
		{
			goto IL_00b8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25469));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25470));
		goto IL_00c4;
	}

IL_00b8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25471));
		bool L_27 = V_0;
		bool L_28 = V_1;
		V_16 = (bool)((int32_t)((int32_t)L_27&(int32_t)L_28));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25472));
		bool L_29 = V_16;
		if (!L_29)
		{
			goto IL_00c4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25473));
		V_10 = (bool)0;
	}

IL_00c4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25474));
		goto IL_01c2;
	}

IL_00c9:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25475));
		int32_t L_30 = V_3;
		V_17 = (bool)((((int32_t)((int32_t)(L_30&1))) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25476));
		bool L_31 = V_17;
		if (!L_31)
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25477));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* L_32;
		L_32 = Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		int8_t L_33 = V_9;
		int8_t L_34 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		NullCheck(L_32);
		int32_t L_35;
		L_35 = VirtualFuncInvoker2< int32_t, int8_t, int8_t >::Invoke(6, L_32, L_33, L_34);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		V_10 = (bool)((((int32_t)((((int32_t)L_35) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25480));
		goto IL_0103;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25481));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		Comparer_1_tFA27DAC2908F666A385A0E5699BB66735365343B* L_36;
		L_36 = Comparer_1_get_Default_m84816461184ACF98D5F66D45F43652587DA47B4F(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		int8_t L_37 = V_9;
		int8_t L_38 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		NullCheck(L_36);
		int32_t L_39;
		L_39 = VirtualFuncInvoker2< int32_t, int8_t, int8_t >::Invoke(6, L_36, L_37, L_38);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		V_10 = (bool)((((int32_t)((((int32_t)L_39) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0103:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25484));
		bool L_40 = V_0;
		bool L_41 = V_1;
		V_18 = (bool)((int32_t)(((((int32_t)L_40) == ((int32_t)0))? 1 : 0)&(int32_t)L_41));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25485));
		bool L_42 = V_18;
		if (!L_42)
		{
			goto IL_0114;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25486));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25487));
		goto IL_0135;
	}

IL_0114:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25488));
		bool L_43 = V_0;
		if (!L_43)
		{
			goto IL_011d;
		}
	}
	{
		bool L_44 = V_1;
		G_B26_0 = ((((int32_t)L_44) == ((int32_t)0))? 1 : 0);
		goto IL_011e;
	}

IL_011d:
	{
		G_B26_0 = 0;
	}

IL_011e:
	{
		V_19 = (bool)G_B26_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25489));
		bool L_45 = V_19;
		if (!L_45)
		{
			goto IL_0129;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25490));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25491));
		goto IL_0135;
	}

IL_0129:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25492));
		bool L_46 = V_0;
		bool L_47 = V_1;
		V_20 = (bool)((int32_t)((int32_t)L_46&(int32_t)L_47));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25493));
		bool L_48 = V_20;
		if (!L_48)
		{
			goto IL_0135;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25494));
		V_10 = (bool)0;
	}

IL_0135:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25495));
		goto IL_01c2;
	}

IL_013a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25496));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_49;
		L_49 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		int8_t L_50 = V_7;
		int8_t L_51 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_49, L_50, L_51);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		V_10 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25499));
		bool L_53 = V_0;
		bool L_54 = V_1;
		V_21 = (bool)((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25500));
		bool L_55 = V_21;
		if (!L_55)
		{
			goto IL_015b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25501));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25502));
		goto IL_017c;
	}

IL_015b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25503));
		bool L_56 = V_0;
		if (!L_56)
		{
			goto IL_0164;
		}
	}
	{
		bool L_57 = V_1;
		G_B36_0 = ((((int32_t)L_57) == ((int32_t)0))? 1 : 0);
		goto IL_0165;
	}

IL_0164:
	{
		G_B36_0 = 0;
	}

IL_0165:
	{
		V_22 = (bool)G_B36_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25504));
		bool L_58 = V_22;
		if (!L_58)
		{
			goto IL_0170;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25505));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25506));
		goto IL_017c;
	}

IL_0170:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25507));
		bool L_59 = V_0;
		bool L_60 = V_1;
		V_23 = (bool)((int32_t)((int32_t)L_59&(int32_t)L_60));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25508));
		bool L_61 = V_23;
		if (!L_61)
		{
			goto IL_017c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25509));
		V_10 = (bool)1;
	}

IL_017c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25510));
		goto IL_01c2;
	}

IL_017e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25511));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_62;
		L_62 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		int8_t L_63 = V_7;
		int8_t L_64 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		NullCheck(L_62);
		bool L_65;
		L_65 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_62, L_63, L_64);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		V_10 = L_65;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25514));
		bool L_66 = V_0;
		bool L_67 = V_1;
		V_24 = (bool)((int32_t)(((((int32_t)L_66) == ((int32_t)0))? 1 : 0)&(int32_t)L_67));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25515));
		bool L_68 = V_24;
		if (!L_68)
		{
			goto IL_019f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25516));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25517));
		goto IL_01c0;
	}

IL_019f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25518));
		bool L_69 = V_0;
		if (!L_69)
		{
			goto IL_01a8;
		}
	}
	{
		bool L_70 = V_1;
		G_B46_0 = ((((int32_t)L_70) == ((int32_t)0))? 1 : 0);
		goto IL_01a9;
	}

IL_01a8:
	{
		G_B46_0 = 0;
	}

IL_01a9:
	{
		V_25 = (bool)G_B46_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25519));
		bool L_71 = V_25;
		if (!L_71)
		{
			goto IL_01b4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25520));
		V_10 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25521));
		goto IL_01c0;
	}

IL_01b4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25522));
		bool L_72 = V_0;
		bool L_73 = V_1;
		V_26 = (bool)((int32_t)((int32_t)L_72&(int32_t)L_73));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25523));
		bool L_74 = V_26;
		if (!L_74)
		{
			goto IL_01c0;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25524));
		V_10 = (bool)1;
	}

IL_01c0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:287>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25525));
		goto IL_01c2;
	}

IL_01c2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25526));
		int32_t L_75 = V_3;
		int32_t L_76 = V_4;
		bool L_77 = V_10;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_75, L_76, L_77, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25528));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25529));
		int32_t L_78 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01d6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25530));
		int32_t L_79 = V_4;
		int32_t L_80 = ___4_len;
		V_27 = (bool)((((int32_t)L_79) < ((int32_t)L_80))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25531));
		bool L_81 = V_27;
		if (L_81)
		{
			goto IL_003d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25532));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25533));
		int32_t L_82 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_82, 1));
	}

IL_01ea:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25534));
		int32_t L_83 = V_3;
		int32_t L_84 = ___4_len;
		V_28 = (bool)((((int32_t)L_83) < ((int32_t)L_84))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25535));
		bool L_85 = V_28;
		if (L_85)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25536));
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25537));
		int32_t L_86 = ___5_imm8;
		V_30 = ((int32_t)(((int32_t)(L_86>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25538));
		int32_t L_87 = V_30;
		V_29 = L_87;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25539));
		int32_t L_88 = V_29;
		switch (L_88)
		{
			case 0:
			{
				goto IL_0223;
			}
			case 1:
			{
				goto IL_0270;
			}
			case 2:
			{
				goto IL_02cb;
			}
			case 3:
			{
				goto IL_02fb;
			}
		}
	}
	{
		goto IL_035a;
	}

IL_0223:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25540));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25541));
		goto IL_0260;
	}

IL_0227:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25542));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25543));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25544));
		goto IL_024f;
	}

IL_022d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25545));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25546));
		int32_t L_89 = V_6;
		int32_t L_90 = V_4;
		int32_t L_91 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		bool L_92;
		L_92 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_90, L_91, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		if (L_92)
		{
			G_B61_0 = L_89;
			goto IL_023f;
		}
		G_B60_0 = L_89;
	}
	{
		G_B62_0 = 0;
		G_B62_1 = G_B60_0;
		goto IL_0240;
	}

IL_023f:
	{
		G_B62_0 = 1;
		G_B62_1 = G_B61_0;
	}

IL_0240:
	{
		int32_t L_93 = V_3;
		V_6 = ((int32_t)(G_B62_1|((int32_t)(G_B62_0<<((int32_t)(L_93&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25548));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25549));
		int32_t L_94 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_94, 1));
	}

IL_024f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25550));
		int32_t L_95 = V_4;
		int32_t L_96 = ___4_len;
		V_31 = (bool)((((int32_t)L_95) < ((int32_t)L_96))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25551));
		bool L_97 = V_31;
		if (L_97)
		{
			goto IL_022d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25552));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25553));
		int32_t L_98 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_98, 1));
	}

IL_0260:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25554));
		int32_t L_99 = V_3;
		int32_t L_100 = ___4_len;
		V_32 = (bool)((((int32_t)L_99) < ((int32_t)L_100))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25555));
		bool L_101 = V_32;
		if (L_101)
		{
			goto IL_0227;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25556));
		goto IL_035a;
	}

IL_0270:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25557));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25558));
		goto IL_02bb;
	}

IL_0274:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25559));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25560));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25561));
		goto IL_02aa;
	}

IL_027a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25562));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25563));
		int32_t L_102 = V_6;
		int32_t L_103 = V_4;
		int32_t L_104 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		bool L_105;
		L_105 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_103, L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		if (!L_105)
		{
			G_B71_0 = L_102;
			goto IL_0297;
		}
		G_B70_0 = L_102;
	}
	{
		int32_t L_106 = V_4;
		int32_t L_107 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		bool L_108;
		L_108 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_106, 1)), L_107, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		if (L_108)
		{
			G_B72_0 = G_B70_0;
			goto IL_029a;
		}
		G_B71_0 = G_B70_0;
	}

IL_0297:
	{
		G_B73_0 = 0;
		G_B73_1 = G_B71_0;
		goto IL_029b;
	}

IL_029a:
	{
		G_B73_0 = 1;
		G_B73_1 = G_B72_0;
	}

IL_029b:
	{
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(G_B73_1|((int32_t)(G_B73_0<<((int32_t)(L_109&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25566));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25567));
		int32_t L_110 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_110, 2));
	}

IL_02aa:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25568));
		int32_t L_111 = V_4;
		int32_t L_112 = ___4_len;
		V_33 = (bool)((((int32_t)L_111) < ((int32_t)L_112))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25569));
		bool L_113 = V_33;
		if (L_113)
		{
			goto IL_027a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25570));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25571));
		int32_t L_114 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_114, 1));
	}

IL_02bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25572));
		int32_t L_115 = V_3;
		int32_t L_116 = ___4_len;
		V_34 = (bool)((((int32_t)L_115) < ((int32_t)L_116))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25573));
		bool L_117 = V_34;
		if (L_117)
		{
			goto IL_0274;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25574));
		goto IL_035a;
	}

IL_02cb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25575));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25576));
		goto IL_02ee;
	}

IL_02cf:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25577));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25578));
		int32_t L_118 = V_6;
		int32_t L_119 = V_3;
		int32_t L_120 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		bool L_121;
		L_121 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_119, L_120, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		if (L_121)
		{
			G_B81_0 = L_118;
			goto IL_02e0;
		}
		G_B80_0 = L_118;
	}
	{
		G_B82_0 = 0;
		G_B82_1 = G_B80_0;
		goto IL_02e1;
	}

IL_02e0:
	{
		G_B82_0 = 1;
		G_B82_1 = G_B81_0;
	}

IL_02e1:
	{
		int32_t L_122 = V_3;
		V_6 = ((int32_t)(G_B82_1|((int32_t)(G_B82_0<<((int32_t)(L_122&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25580));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25581));
		int32_t L_123 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_123, 1));
	}

IL_02ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25582));
		int32_t L_124 = V_3;
		int32_t L_125 = ___4_len;
		V_35 = (bool)((((int32_t)L_124) < ((int32_t)L_125))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25583));
		bool L_126 = V_35;
		if (L_126)
		{
			goto IL_02cf;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25584));
		goto IL_035a;
	}

IL_02fb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25585));
		int32_t L_127 = ___6_allOnes;
		V_6 = L_127;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25586));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25587));
		goto IL_034d;
	}

IL_0303:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25588));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25589));
		int32_t L_128 = V_3;
		V_36 = L_128;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25590));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25591));
		goto IL_033a;
	}

IL_030c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25592));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25593));
		int32_t L_129 = V_4;
		int32_t L_130 = V_36;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		bool L_131;
		L_131 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_129, L_130, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		V_37 = (bool)((((int32_t)L_131) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25595));
		bool L_132 = V_37;
		if (!L_132)
		{
			goto IL_032d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25596));
		int32_t L_133 = V_6;
		int32_t L_134 = V_3;
		V_6 = ((int32_t)(L_133&((~((int32_t)(1<<((int32_t)(L_134&((int32_t)31)))))))));
	}

IL_032d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25597));
		int32_t L_135 = V_36;
		V_36 = ((int32_t)il2cpp_codegen_add(L_135, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25598));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25599));
		int32_t L_136 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_136, 1));
	}

IL_033a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25600));
		int32_t L_137 = V_4;
		int32_t L_138 = ___4_len;
		int32_t L_139 = V_3;
		V_38 = (bool)((((int32_t)L_137) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_138, L_139))))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25601));
		bool L_140 = V_38;
		if (L_140)
		{
			goto IL_030c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25602));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25603));
		int32_t L_141 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_141, 1));
	}

IL_034d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25604));
		int32_t L_142 = V_3;
		int32_t L_143 = ___4_len;
		V_39 = (bool)((((int32_t)L_142) < ((int32_t)L_143))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25605));
		bool L_144 = V_39;
		if (L_144)
		{
			goto IL_0303;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:340>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25606));
		goto IL_035a;
	}

IL_035a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25607));
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25608));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25609));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25610));
		goto IL_0401;
	}

IL_0366:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25611));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25612));
		int32_t L_145 = ___5_imm8;
		V_40 = (bool)((!(((uint32_t)((int32_t)(L_145&((int32_t)16)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25613));
		bool L_146 = V_40;
		if (!L_146)
		{
			goto IL_03ee;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25614));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25615));
		int32_t L_147 = ___5_imm8;
		V_41 = (bool)((!(((uint32_t)((int32_t)(L_147&((int32_t)32)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25616));
		bool L_148 = V_41;
		if (!L_148)
		{
			goto IL_03dc;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25617));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25618));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_149;
		L_149 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		int8_t* L_150 = ___2_b;
		int32_t L_151 = V_3;
		uint32_t L_152 = sizeof(int8_t);
		int8_t L_153 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_150, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_151), (int32_t)L_152)))));
		il2cpp_codegen_initobj((&V_43), sizeof(int8_t));
		int8_t L_154 = V_43;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		NullCheck(L_149);
		bool L_155;
		L_155 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_149, L_153, L_154);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		V_42 = L_155;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25621));
		bool L_156 = V_42;
		if (!L_156)
		{
			goto IL_03b3;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25622));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25623));
		V_1 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25624));
	}

IL_03b3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25625));
		bool L_157 = V_1;
		V_44 = L_157;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25626));
		bool L_158 = V_44;
		if (!L_158)
		{
			goto IL_03ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25627));
		int32_t L_159 = V_5;
		int32_t L_160 = V_6;
		int32_t L_161 = V_3;
		V_5 = ((int32_t)(L_159|((int32_t)(L_160&((int32_t)(1<<((int32_t)(L_161&((int32_t)31)))))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25628));
		goto IL_03d9;
	}

IL_03ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25629));
		int32_t L_162 = V_5;
		int32_t L_163 = V_6;
		int32_t L_164 = V_3;
		V_5 = ((int32_t)(L_162|((int32_t)(((~L_163))&((int32_t)(1<<((int32_t)(L_164&((int32_t)31)))))))));
	}

IL_03d9:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25630));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25631));
		goto IL_03eb;
	}

IL_03dc:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25632));
		int32_t L_165 = V_5;
		int32_t L_166 = V_6;
		int32_t L_167 = V_3;
		V_5 = ((int32_t)(L_165|((int32_t)(((~L_166))&((int32_t)(1<<((int32_t)(L_167&((int32_t)31)))))))));
	}

IL_03eb:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25633));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25634));
		goto IL_03fc;
	}

IL_03ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25635));
		int32_t L_168 = V_5;
		int32_t L_169 = V_6;
		int32_t L_170 = V_3;
		V_5 = ((int32_t)(L_168|((int32_t)(L_169&((int32_t)(1<<((int32_t)(L_170&((int32_t)31)))))))));
	}

IL_03fc:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25636));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25637));
		int32_t L_171 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_171, 1));
	}

IL_0401:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25638));
		int32_t L_172 = V_3;
		int32_t L_173 = ___4_len;
		V_45 = (bool)((((int32_t)L_172) < ((int32_t)L_173))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25639));
		bool L_174 = V_45;
		if (L_174)
		{
			goto IL_0366;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25640));
		int32_t L_175 = V_5;
		V_46 = L_175;
		goto IL_0415;
	}

IL_0415:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25641));
		int32_t L_176 = V_46;
		return L_176;
	}
}
// Method Definition Index: 117202
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	uint16_t V_7 = 0;
	bool V_8 = false;
	uint16_t V_9 = 0;
	bool V_10 = false;
	bool V_11 = false;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	bool V_21 = false;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	bool V_27 = false;
	bool V_28 = false;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	bool V_31 = false;
	bool V_32 = false;
	bool V_33 = false;
	bool V_34 = false;
	bool V_35 = false;
	int32_t V_36 = 0;
	bool V_37 = false;
	bool V_38 = false;
	bool V_39 = false;
	bool V_40 = false;
	bool V_41 = false;
	bool V_42 = false;
	uint16_t V_43 = 0;
	bool V_44 = false;
	bool V_45 = false;
	int32_t V_46 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_5), (&V_6), (&V_7), (&V_9), (&V_10), (&V_36));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25436));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25437));
	int32_t G_B13_0 = 0;
	int32_t G_B26_0 = 0;
	int32_t G_B36_0 = 0;
	int32_t G_B46_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B62_0 = 0;
	int32_t G_B62_1 = 0;
	int32_t G_B71_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B72_0 = 0;
	int32_t G_B73_0 = 0;
	int32_t G_B73_1 = 0;
	int32_t G_B81_0 = 0;
	int32_t G_B80_0 = 0;
	int32_t G_B82_0 = 0;
	int32_t G_B82_1 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25438));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25439));
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25440));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25441));
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25442));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25443));
		goto IL_01ea;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25444));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25445));
		uint16_t* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = sizeof(uint16_t);
		uint16_t L_3 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))));
		V_7 = L_3;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25446));
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		V_8 = (bool)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25447));
		bool L_6 = V_8;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25448));
		V_0 = (bool)1;
	}

IL_0033:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25449));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25450));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25451));
		goto IL_01d6;
	}

IL_003d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25452));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25453));
		uint16_t* L_7 = ___2_b;
		int32_t L_8 = V_4;
		uint32_t L_9 = sizeof(uint16_t);
		uint16_t L_10 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))));
		V_9 = L_10;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25454));
		int32_t L_11 = V_4;
		int32_t L_12 = ___3_blen;
		V_11 = (bool)((((int32_t)L_11) == ((int32_t)L_12))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25455));
		bool L_13 = V_11;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25456));
		V_1 = (bool)1;
	}

IL_005e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25457));
		int32_t L_14 = ___5_imm8;
		V_13 = ((int32_t)(((int32_t)(L_14>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25458));
		int32_t L_15 = V_13;
		V_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25459));
		int32_t L_16 = V_12;
		switch (L_16)
		{
			case 0:
			{
				goto IL_0082;
			}
			case 1:
			{
				goto IL_00c9;
			}
			case 2:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_017e;
	}

IL_0082:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25460));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_17;
		L_17 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		uint16_t L_18 = V_7;
		uint16_t L_19 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		NullCheck(L_17);
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_17, L_18, L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		V_10 = L_20;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25463));
		bool L_21 = V_0;
		bool L_22 = V_1;
		V_14 = (bool)((int32_t)(((((int32_t)L_21) == ((int32_t)0))? 1 : 0)&(int32_t)L_22));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25464));
		bool L_23 = V_14;
		if (!L_23)
		{
			goto IL_00a3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25465));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25466));
		goto IL_00c4;
	}

IL_00a3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25467));
		bool L_24 = V_0;
		if (!L_24)
		{
			goto IL_00ac;
		}
	}
	{
		bool L_25 = V_1;
		G_B13_0 = ((((int32_t)L_25) == ((int32_t)0))? 1 : 0);
		goto IL_00ad;
	}

IL_00ac:
	{
		G_B13_0 = 0;
	}

IL_00ad:
	{
		V_15 = (bool)G_B13_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25468));
		bool L_26 = V_15;
		if (!L_26)
		{
			goto IL_00b8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25469));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25470));
		goto IL_00c4;
	}

IL_00b8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25471));
		bool L_27 = V_0;
		bool L_28 = V_1;
		V_16 = (bool)((int32_t)((int32_t)L_27&(int32_t)L_28));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25472));
		bool L_29 = V_16;
		if (!L_29)
		{
			goto IL_00c4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25473));
		V_10 = (bool)0;
	}

IL_00c4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25474));
		goto IL_01c2;
	}

IL_00c9:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25475));
		int32_t L_30 = V_3;
		V_17 = (bool)((((int32_t)((int32_t)(L_30&1))) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25476));
		bool L_31 = V_17;
		if (!L_31)
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25477));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* L_32;
		L_32 = Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		uint16_t L_33 = V_9;
		uint16_t L_34 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		NullCheck(L_32);
		int32_t L_35;
		L_35 = VirtualFuncInvoker2< int32_t, uint16_t, uint16_t >::Invoke(6, L_32, L_33, L_34);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		V_10 = (bool)((((int32_t)((((int32_t)L_35) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25480));
		goto IL_0103;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25481));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		Comparer_1_t58CF625431A0184A14FF0A33D14229F8F6EA3C98* L_36;
		L_36 = Comparer_1_get_Default_m5B4E9A09E85C87692450A9D2BC5C99C3E5DC1E36(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		uint16_t L_37 = V_9;
		uint16_t L_38 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		NullCheck(L_36);
		int32_t L_39;
		L_39 = VirtualFuncInvoker2< int32_t, uint16_t, uint16_t >::Invoke(6, L_36, L_37, L_38);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		V_10 = (bool)((((int32_t)((((int32_t)L_39) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0103:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25484));
		bool L_40 = V_0;
		bool L_41 = V_1;
		V_18 = (bool)((int32_t)(((((int32_t)L_40) == ((int32_t)0))? 1 : 0)&(int32_t)L_41));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25485));
		bool L_42 = V_18;
		if (!L_42)
		{
			goto IL_0114;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25486));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25487));
		goto IL_0135;
	}

IL_0114:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25488));
		bool L_43 = V_0;
		if (!L_43)
		{
			goto IL_011d;
		}
	}
	{
		bool L_44 = V_1;
		G_B26_0 = ((((int32_t)L_44) == ((int32_t)0))? 1 : 0);
		goto IL_011e;
	}

IL_011d:
	{
		G_B26_0 = 0;
	}

IL_011e:
	{
		V_19 = (bool)G_B26_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25489));
		bool L_45 = V_19;
		if (!L_45)
		{
			goto IL_0129;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25490));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25491));
		goto IL_0135;
	}

IL_0129:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25492));
		bool L_46 = V_0;
		bool L_47 = V_1;
		V_20 = (bool)((int32_t)((int32_t)L_46&(int32_t)L_47));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25493));
		bool L_48 = V_20;
		if (!L_48)
		{
			goto IL_0135;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25494));
		V_10 = (bool)0;
	}

IL_0135:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25495));
		goto IL_01c2;
	}

IL_013a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25496));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_49;
		L_49 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		uint16_t L_50 = V_7;
		uint16_t L_51 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_49, L_50, L_51);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		V_10 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25499));
		bool L_53 = V_0;
		bool L_54 = V_1;
		V_21 = (bool)((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25500));
		bool L_55 = V_21;
		if (!L_55)
		{
			goto IL_015b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25501));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25502));
		goto IL_017c;
	}

IL_015b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25503));
		bool L_56 = V_0;
		if (!L_56)
		{
			goto IL_0164;
		}
	}
	{
		bool L_57 = V_1;
		G_B36_0 = ((((int32_t)L_57) == ((int32_t)0))? 1 : 0);
		goto IL_0165;
	}

IL_0164:
	{
		G_B36_0 = 0;
	}

IL_0165:
	{
		V_22 = (bool)G_B36_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25504));
		bool L_58 = V_22;
		if (!L_58)
		{
			goto IL_0170;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25505));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25506));
		goto IL_017c;
	}

IL_0170:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25507));
		bool L_59 = V_0;
		bool L_60 = V_1;
		V_23 = (bool)((int32_t)((int32_t)L_59&(int32_t)L_60));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25508));
		bool L_61 = V_23;
		if (!L_61)
		{
			goto IL_017c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25509));
		V_10 = (bool)1;
	}

IL_017c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25510));
		goto IL_01c2;
	}

IL_017e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25511));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_62;
		L_62 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		uint16_t L_63 = V_7;
		uint16_t L_64 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		NullCheck(L_62);
		bool L_65;
		L_65 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_62, L_63, L_64);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		V_10 = L_65;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25514));
		bool L_66 = V_0;
		bool L_67 = V_1;
		V_24 = (bool)((int32_t)(((((int32_t)L_66) == ((int32_t)0))? 1 : 0)&(int32_t)L_67));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25515));
		bool L_68 = V_24;
		if (!L_68)
		{
			goto IL_019f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25516));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25517));
		goto IL_01c0;
	}

IL_019f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25518));
		bool L_69 = V_0;
		if (!L_69)
		{
			goto IL_01a8;
		}
	}
	{
		bool L_70 = V_1;
		G_B46_0 = ((((int32_t)L_70) == ((int32_t)0))? 1 : 0);
		goto IL_01a9;
	}

IL_01a8:
	{
		G_B46_0 = 0;
	}

IL_01a9:
	{
		V_25 = (bool)G_B46_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25519));
		bool L_71 = V_25;
		if (!L_71)
		{
			goto IL_01b4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25520));
		V_10 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25521));
		goto IL_01c0;
	}

IL_01b4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25522));
		bool L_72 = V_0;
		bool L_73 = V_1;
		V_26 = (bool)((int32_t)((int32_t)L_72&(int32_t)L_73));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25523));
		bool L_74 = V_26;
		if (!L_74)
		{
			goto IL_01c0;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25524));
		V_10 = (bool)1;
	}

IL_01c0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:287>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25525));
		goto IL_01c2;
	}

IL_01c2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25526));
		int32_t L_75 = V_3;
		int32_t L_76 = V_4;
		bool L_77 = V_10;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_75, L_76, L_77, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25528));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25529));
		int32_t L_78 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01d6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25530));
		int32_t L_79 = V_4;
		int32_t L_80 = ___4_len;
		V_27 = (bool)((((int32_t)L_79) < ((int32_t)L_80))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25531));
		bool L_81 = V_27;
		if (L_81)
		{
			goto IL_003d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25532));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25533));
		int32_t L_82 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_82, 1));
	}

IL_01ea:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25534));
		int32_t L_83 = V_3;
		int32_t L_84 = ___4_len;
		V_28 = (bool)((((int32_t)L_83) < ((int32_t)L_84))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25535));
		bool L_85 = V_28;
		if (L_85)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25536));
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25537));
		int32_t L_86 = ___5_imm8;
		V_30 = ((int32_t)(((int32_t)(L_86>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25538));
		int32_t L_87 = V_30;
		V_29 = L_87;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25539));
		int32_t L_88 = V_29;
		switch (L_88)
		{
			case 0:
			{
				goto IL_0223;
			}
			case 1:
			{
				goto IL_0270;
			}
			case 2:
			{
				goto IL_02cb;
			}
			case 3:
			{
				goto IL_02fb;
			}
		}
	}
	{
		goto IL_035a;
	}

IL_0223:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25540));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25541));
		goto IL_0260;
	}

IL_0227:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25542));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25543));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25544));
		goto IL_024f;
	}

IL_022d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25545));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25546));
		int32_t L_89 = V_6;
		int32_t L_90 = V_4;
		int32_t L_91 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		bool L_92;
		L_92 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_90, L_91, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		if (L_92)
		{
			G_B61_0 = L_89;
			goto IL_023f;
		}
		G_B60_0 = L_89;
	}
	{
		G_B62_0 = 0;
		G_B62_1 = G_B60_0;
		goto IL_0240;
	}

IL_023f:
	{
		G_B62_0 = 1;
		G_B62_1 = G_B61_0;
	}

IL_0240:
	{
		int32_t L_93 = V_3;
		V_6 = ((int32_t)(G_B62_1|((int32_t)(G_B62_0<<((int32_t)(L_93&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25548));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25549));
		int32_t L_94 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_94, 1));
	}

IL_024f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25550));
		int32_t L_95 = V_4;
		int32_t L_96 = ___4_len;
		V_31 = (bool)((((int32_t)L_95) < ((int32_t)L_96))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25551));
		bool L_97 = V_31;
		if (L_97)
		{
			goto IL_022d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25552));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25553));
		int32_t L_98 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_98, 1));
	}

IL_0260:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25554));
		int32_t L_99 = V_3;
		int32_t L_100 = ___4_len;
		V_32 = (bool)((((int32_t)L_99) < ((int32_t)L_100))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25555));
		bool L_101 = V_32;
		if (L_101)
		{
			goto IL_0227;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25556));
		goto IL_035a;
	}

IL_0270:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25557));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25558));
		goto IL_02bb;
	}

IL_0274:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25559));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25560));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25561));
		goto IL_02aa;
	}

IL_027a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25562));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25563));
		int32_t L_102 = V_6;
		int32_t L_103 = V_4;
		int32_t L_104 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		bool L_105;
		L_105 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_103, L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		if (!L_105)
		{
			G_B71_0 = L_102;
			goto IL_0297;
		}
		G_B70_0 = L_102;
	}
	{
		int32_t L_106 = V_4;
		int32_t L_107 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		bool L_108;
		L_108 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_106, 1)), L_107, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		if (L_108)
		{
			G_B72_0 = G_B70_0;
			goto IL_029a;
		}
		G_B71_0 = G_B70_0;
	}

IL_0297:
	{
		G_B73_0 = 0;
		G_B73_1 = G_B71_0;
		goto IL_029b;
	}

IL_029a:
	{
		G_B73_0 = 1;
		G_B73_1 = G_B72_0;
	}

IL_029b:
	{
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(G_B73_1|((int32_t)(G_B73_0<<((int32_t)(L_109&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25566));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25567));
		int32_t L_110 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_110, 2));
	}

IL_02aa:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25568));
		int32_t L_111 = V_4;
		int32_t L_112 = ___4_len;
		V_33 = (bool)((((int32_t)L_111) < ((int32_t)L_112))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25569));
		bool L_113 = V_33;
		if (L_113)
		{
			goto IL_027a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25570));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25571));
		int32_t L_114 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_114, 1));
	}

IL_02bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25572));
		int32_t L_115 = V_3;
		int32_t L_116 = ___4_len;
		V_34 = (bool)((((int32_t)L_115) < ((int32_t)L_116))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25573));
		bool L_117 = V_34;
		if (L_117)
		{
			goto IL_0274;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25574));
		goto IL_035a;
	}

IL_02cb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25575));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25576));
		goto IL_02ee;
	}

IL_02cf:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25577));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25578));
		int32_t L_118 = V_6;
		int32_t L_119 = V_3;
		int32_t L_120 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		bool L_121;
		L_121 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_119, L_120, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		if (L_121)
		{
			G_B81_0 = L_118;
			goto IL_02e0;
		}
		G_B80_0 = L_118;
	}
	{
		G_B82_0 = 0;
		G_B82_1 = G_B80_0;
		goto IL_02e1;
	}

IL_02e0:
	{
		G_B82_0 = 1;
		G_B82_1 = G_B81_0;
	}

IL_02e1:
	{
		int32_t L_122 = V_3;
		V_6 = ((int32_t)(G_B82_1|((int32_t)(G_B82_0<<((int32_t)(L_122&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25580));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25581));
		int32_t L_123 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_123, 1));
	}

IL_02ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25582));
		int32_t L_124 = V_3;
		int32_t L_125 = ___4_len;
		V_35 = (bool)((((int32_t)L_124) < ((int32_t)L_125))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25583));
		bool L_126 = V_35;
		if (L_126)
		{
			goto IL_02cf;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25584));
		goto IL_035a;
	}

IL_02fb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25585));
		int32_t L_127 = ___6_allOnes;
		V_6 = L_127;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25586));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25587));
		goto IL_034d;
	}

IL_0303:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25588));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25589));
		int32_t L_128 = V_3;
		V_36 = L_128;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25590));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25591));
		goto IL_033a;
	}

IL_030c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25592));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25593));
		int32_t L_129 = V_4;
		int32_t L_130 = V_36;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		bool L_131;
		L_131 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_129, L_130, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		V_37 = (bool)((((int32_t)L_131) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25595));
		bool L_132 = V_37;
		if (!L_132)
		{
			goto IL_032d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25596));
		int32_t L_133 = V_6;
		int32_t L_134 = V_3;
		V_6 = ((int32_t)(L_133&((~((int32_t)(1<<((int32_t)(L_134&((int32_t)31)))))))));
	}

IL_032d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25597));
		int32_t L_135 = V_36;
		V_36 = ((int32_t)il2cpp_codegen_add(L_135, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25598));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25599));
		int32_t L_136 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_136, 1));
	}

IL_033a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25600));
		int32_t L_137 = V_4;
		int32_t L_138 = ___4_len;
		int32_t L_139 = V_3;
		V_38 = (bool)((((int32_t)L_137) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_138, L_139))))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25601));
		bool L_140 = V_38;
		if (L_140)
		{
			goto IL_030c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25602));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25603));
		int32_t L_141 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_141, 1));
	}

IL_034d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25604));
		int32_t L_142 = V_3;
		int32_t L_143 = ___4_len;
		V_39 = (bool)((((int32_t)L_142) < ((int32_t)L_143))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25605));
		bool L_144 = V_39;
		if (L_144)
		{
			goto IL_0303;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:340>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25606));
		goto IL_035a;
	}

IL_035a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25607));
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25608));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25609));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25610));
		goto IL_0401;
	}

IL_0366:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25611));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25612));
		int32_t L_145 = ___5_imm8;
		V_40 = (bool)((!(((uint32_t)((int32_t)(L_145&((int32_t)16)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25613));
		bool L_146 = V_40;
		if (!L_146)
		{
			goto IL_03ee;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25614));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25615));
		int32_t L_147 = ___5_imm8;
		V_41 = (bool)((!(((uint32_t)((int32_t)(L_147&((int32_t)32)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25616));
		bool L_148 = V_41;
		if (!L_148)
		{
			goto IL_03dc;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25617));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25618));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_149;
		L_149 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		uint16_t* L_150 = ___2_b;
		int32_t L_151 = V_3;
		uint32_t L_152 = sizeof(uint16_t);
		uint16_t L_153 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_150, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_151), (int32_t)L_152)))));
		il2cpp_codegen_initobj((&V_43), sizeof(uint16_t));
		uint16_t L_154 = V_43;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		NullCheck(L_149);
		bool L_155;
		L_155 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_149, L_153, L_154);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		V_42 = L_155;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25621));
		bool L_156 = V_42;
		if (!L_156)
		{
			goto IL_03b3;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25622));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25623));
		V_1 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25624));
	}

IL_03b3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25625));
		bool L_157 = V_1;
		V_44 = L_157;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25626));
		bool L_158 = V_44;
		if (!L_158)
		{
			goto IL_03ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25627));
		int32_t L_159 = V_5;
		int32_t L_160 = V_6;
		int32_t L_161 = V_3;
		V_5 = ((int32_t)(L_159|((int32_t)(L_160&((int32_t)(1<<((int32_t)(L_161&((int32_t)31)))))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25628));
		goto IL_03d9;
	}

IL_03ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25629));
		int32_t L_162 = V_5;
		int32_t L_163 = V_6;
		int32_t L_164 = V_3;
		V_5 = ((int32_t)(L_162|((int32_t)(((~L_163))&((int32_t)(1<<((int32_t)(L_164&((int32_t)31)))))))));
	}

IL_03d9:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25630));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25631));
		goto IL_03eb;
	}

IL_03dc:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25632));
		int32_t L_165 = V_5;
		int32_t L_166 = V_6;
		int32_t L_167 = V_3;
		V_5 = ((int32_t)(L_165|((int32_t)(((~L_166))&((int32_t)(1<<((int32_t)(L_167&((int32_t)31)))))))));
	}

IL_03eb:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25633));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25634));
		goto IL_03fc;
	}

IL_03ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25635));
		int32_t L_168 = V_5;
		int32_t L_169 = V_6;
		int32_t L_170 = V_3;
		V_5 = ((int32_t)(L_168|((int32_t)(L_169&((int32_t)(1<<((int32_t)(L_170&((int32_t)31)))))))));
	}

IL_03fc:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25636));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25637));
		int32_t L_171 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_171, 1));
	}

IL_0401:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25638));
		int32_t L_172 = V_3;
		int32_t L_173 = ___4_len;
		V_45 = (bool)((((int32_t)L_172) < ((int32_t)L_173))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25639));
		bool L_174 = V_45;
		if (L_174)
		{
			goto IL_0366;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25640));
		int32_t L_175 = V_5;
		V_46 = L_175;
		goto IL_0415;
	}

IL_0415:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25641));
		int32_t L_176 = V_46;
		return L_176;
	}
}
// Method Definition Index: 117202
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStrCmpIntRes2_TisIl2CppFullySharedGenericStruct_m5BBC7FD25430C93A4DCF34A210DE56367BA1E204_gshared (Il2CppFullySharedGenericStruct* ___0_a, int32_t ___1_alen, Il2CppFullySharedGenericStruct* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_3 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	const Il2CppFullySharedGenericStruct L_10 = L_3;
	const Il2CppFullySharedGenericStruct L_18 = L_3;
	const Il2CppFullySharedGenericStruct L_33 = L_3;
	const Il2CppFullySharedGenericStruct L_37 = L_3;
	const Il2CppFullySharedGenericStruct L_50 = L_3;
	const Il2CppFullySharedGenericStruct L_63 = L_3;
	const Il2CppFullySharedGenericStruct L_153 = L_3;
	const Il2CppFullySharedGenericStruct L_19 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	const Il2CppFullySharedGenericStruct L_34 = L_19;
	const Il2CppFullySharedGenericStruct L_38 = L_19;
	const Il2CppFullySharedGenericStruct L_51 = L_19;
	const Il2CppFullySharedGenericStruct L_64 = L_19;
	const Il2CppFullySharedGenericStruct L_154 = L_19;
	bool V_0 = false;
	bool V_1 = false;
	StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	Il2CppFullySharedGenericStruct V_7 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	memset(V_7, 0, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	bool V_8 = false;
	Il2CppFullySharedGenericStruct V_9 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	memset(V_9, 0, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	bool V_10 = false;
	bool V_11 = false;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	bool V_21 = false;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	bool V_27 = false;
	bool V_28 = false;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	bool V_31 = false;
	bool V_32 = false;
	bool V_33 = false;
	bool V_34 = false;
	bool V_35 = false;
	int32_t V_36 = 0;
	bool V_37 = false;
	bool V_38 = false;
	bool V_39 = false;
	bool V_40 = false;
	bool V_41 = false;
	bool V_42 = false;
	Il2CppFullySharedGenericStruct V_43 = alloca(SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	memset(V_43, 0, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
	bool V_44 = false;
	bool V_45 = false;
	int32_t V_46 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_5), (&V_6), V_7, V_9, (&V_10), (&V_36));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25436));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25437));
	int32_t G_B13_0 = 0;
	int32_t G_B26_0 = 0;
	int32_t G_B36_0 = 0;
	int32_t G_B46_0 = 0;
	int32_t G_B61_0 = 0;
	int32_t G_B60_0 = 0;
	int32_t G_B62_0 = 0;
	int32_t G_B62_1 = 0;
	int32_t G_B71_0 = 0;
	int32_t G_B70_0 = 0;
	int32_t G_B72_0 = 0;
	int32_t G_B73_0 = 0;
	int32_t G_B73_1 = 0;
	int32_t G_B81_0 = 0;
	int32_t G_B80_0 = 0;
	int32_t G_B82_0 = 0;
	int32_t G_B82_1 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25438));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:223>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25439));
		V_0 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:224>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25440));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:225>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25441));
		il2cpp_codegen_initobj((&V_2), sizeof(StrBoolArray_tCA66E1F688A4BC6FA749195F867F59E523508DD6));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25442));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25443));
		goto IL_01ea;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25444));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:230>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25445));
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		int32_t L_1 = V_3;
		uint32_t L_2 = SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77;
		il2cpp_codegen_memcpy(L_3, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_1), (int32_t)L_2)))), SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(V_7, L_3, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:232>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25446));
		int32_t L_4 = V_3;
		int32_t L_5 = ___1_alen;
		V_8 = (bool)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25447));
		bool L_6 = V_8;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:233>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25448));
		V_0 = (bool)1;
	}

IL_0033:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:235>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25449));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25450));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25451));
		goto IL_01d6;
	}

IL_003d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25452));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:238>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25453));
		Il2CppFullySharedGenericStruct* L_7 = ___2_b;
		int32_t L_8 = V_4;
		uint32_t L_9 = SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77;
		il2cpp_codegen_memcpy(L_10, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_7, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_8), (int32_t)L_9)))), SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(V_9, L_10, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:239>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25454));
		int32_t L_11 = V_4;
		int32_t L_12 = ___3_blen;
		V_11 = (bool)((((int32_t)L_11) == ((int32_t)L_12))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25455));
		bool L_13 = V_11;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:240>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25456));
		V_1 = (bool)1;
	}

IL_005e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:245>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25457));
		int32_t L_14 = ___5_imm8;
		V_13 = ((int32_t)(((int32_t)(L_14>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25458));
		int32_t L_15 = V_13;
		V_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25459));
		int32_t L_16 = V_12;
		switch (L_16)
		{
			case 0:
			{
				goto IL_0082;
			}
			case 1:
			{
				goto IL_00c9;
			}
			case 2:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_017e;
	}

IL_0082:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:248>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25460));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_17;
		L_17 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25461));
		il2cpp_codegen_memcpy(L_18, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_19, V_9, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		NullCheck(L_17);
		bool L_20;
		L_20 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_17, L_18, L_19);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25462));
		V_10 = L_20;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:249>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25463));
		bool L_21 = V_0;
		bool L_22 = V_1;
		V_14 = (bool)((int32_t)(((((int32_t)L_21) == ((int32_t)0))? 1 : 0)&(int32_t)L_22));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25464));
		bool L_23 = V_14;
		if (!L_23)
		{
			goto IL_00a3;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:250>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25465));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25466));
		goto IL_00c4;
	}

IL_00a3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:251>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25467));
		bool L_24 = V_0;
		if (!L_24)
		{
			goto IL_00ac;
		}
	}
	{
		bool L_25 = V_1;
		G_B13_0 = ((((int32_t)L_25) == ((int32_t)0))? 1 : 0);
		goto IL_00ad;
	}

IL_00ac:
	{
		G_B13_0 = 0;
	}

IL_00ad:
	{
		V_15 = (bool)G_B13_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25468));
		bool L_26 = V_15;
		if (!L_26)
		{
			goto IL_00b8;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:252>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25469));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25470));
		goto IL_00c4;
	}

IL_00b8:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:253>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25471));
		bool L_27 = V_0;
		bool L_28 = V_1;
		V_16 = (bool)((int32_t)((int32_t)L_27&(int32_t)L_28));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25472));
		bool L_29 = V_16;
		if (!L_29)
		{
			goto IL_00c4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:254>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25473));
		V_10 = (bool)0;
	}

IL_00c4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:255>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25474));
		goto IL_01c2;
	}

IL_00c9:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:258>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25475));
		int32_t L_30 = V_3;
		V_17 = (bool)((((int32_t)((int32_t)(L_30&1))) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25476));
		bool L_31 = V_17;
		if (!L_31)
		{
			goto IL_00ed;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:259>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25477));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* L_32;
		L_32 = ((  Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25478));
		il2cpp_codegen_memcpy(L_33, V_9, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_34, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		NullCheck(L_32);
		int32_t L_35;
		L_35 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(6, L_32, L_33, L_34);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25479));
		V_10 = (bool)((((int32_t)((((int32_t)L_35) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25480));
		goto IL_0103;
	}

IL_00ed:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:261>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25481));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* L_36;
		L_36 = ((  Comparer_1_t535E02B3998AA8B49230077EF0DFCB16BA44C985* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25482));
		il2cpp_codegen_memcpy(L_37, V_9, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_38, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		NullCheck(L_36);
		int32_t L_39;
		L_39 = VirtualFuncInvoker2Invoker< int32_t, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(6, L_36, L_37, L_38);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25483));
		V_10 = (bool)((((int32_t)((((int32_t)L_39) > ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0103:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:263>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25484));
		bool L_40 = V_0;
		bool L_41 = V_1;
		V_18 = (bool)((int32_t)(((((int32_t)L_40) == ((int32_t)0))? 1 : 0)&(int32_t)L_41));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25485));
		bool L_42 = V_18;
		if (!L_42)
		{
			goto IL_0114;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:264>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25486));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25487));
		goto IL_0135;
	}

IL_0114:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:265>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25488));
		bool L_43 = V_0;
		if (!L_43)
		{
			goto IL_011d;
		}
	}
	{
		bool L_44 = V_1;
		G_B26_0 = ((((int32_t)L_44) == ((int32_t)0))? 1 : 0);
		goto IL_011e;
	}

IL_011d:
	{
		G_B26_0 = 0;
	}

IL_011e:
	{
		V_19 = (bool)G_B26_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25489));
		bool L_45 = V_19;
		if (!L_45)
		{
			goto IL_0129;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:266>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25490));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25491));
		goto IL_0135;
	}

IL_0129:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:267>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25492));
		bool L_46 = V_0;
		bool L_47 = V_1;
		V_20 = (bool)((int32_t)((int32_t)L_46&(int32_t)L_47));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25493));
		bool L_48 = V_20;
		if (!L_48)
		{
			goto IL_0135;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:268>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25494));
		V_10 = (bool)0;
	}

IL_0135:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:269>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25495));
		goto IL_01c2;
	}

IL_013a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:271>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25496));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_49;
		L_49 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25497));
		il2cpp_codegen_memcpy(L_50, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_51, V_9, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		NullCheck(L_49);
		bool L_52;
		L_52 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_49, L_50, L_51);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25498));
		V_10 = L_52;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:272>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25499));
		bool L_53 = V_0;
		bool L_54 = V_1;
		V_21 = (bool)((int32_t)(((((int32_t)L_53) == ((int32_t)0))? 1 : 0)&(int32_t)L_54));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25500));
		bool L_55 = V_21;
		if (!L_55)
		{
			goto IL_015b;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:273>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25501));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25502));
		goto IL_017c;
	}

IL_015b:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:274>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25503));
		bool L_56 = V_0;
		if (!L_56)
		{
			goto IL_0164;
		}
	}
	{
		bool L_57 = V_1;
		G_B36_0 = ((((int32_t)L_57) == ((int32_t)0))? 1 : 0);
		goto IL_0165;
	}

IL_0164:
	{
		G_B36_0 = 0;
	}

IL_0165:
	{
		V_22 = (bool)G_B36_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25504));
		bool L_58 = V_22;
		if (!L_58)
		{
			goto IL_0170;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:275>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25505));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25506));
		goto IL_017c;
	}

IL_0170:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:276>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25507));
		bool L_59 = V_0;
		bool L_60 = V_1;
		V_23 = (bool)((int32_t)((int32_t)L_59&(int32_t)L_60));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25508));
		bool L_61 = V_23;
		if (!L_61)
		{
			goto IL_017c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:277>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25509));
		V_10 = (bool)1;
	}

IL_017c:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:278>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25510));
		goto IL_01c2;
	}

IL_017e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:280>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25511));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_62;
		L_62 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25512));
		il2cpp_codegen_memcpy(L_63, V_7, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_64, V_9, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		NullCheck(L_62);
		bool L_65;
		L_65 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_62, L_63, L_64);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25513));
		V_10 = L_65;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:281>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25514));
		bool L_66 = V_0;
		bool L_67 = V_1;
		V_24 = (bool)((int32_t)(((((int32_t)L_66) == ((int32_t)0))? 1 : 0)&(int32_t)L_67));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25515));
		bool L_68 = V_24;
		if (!L_68)
		{
			goto IL_019f;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:282>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25516));
		V_10 = (bool)0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25517));
		goto IL_01c0;
	}

IL_019f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:283>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25518));
		bool L_69 = V_0;
		if (!L_69)
		{
			goto IL_01a8;
		}
	}
	{
		bool L_70 = V_1;
		G_B46_0 = ((((int32_t)L_70) == ((int32_t)0))? 1 : 0);
		goto IL_01a9;
	}

IL_01a8:
	{
		G_B46_0 = 0;
	}

IL_01a9:
	{
		V_25 = (bool)G_B46_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25519));
		bool L_71 = V_25;
		if (!L_71)
		{
			goto IL_01b4;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:284>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25520));
		V_10 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25521));
		goto IL_01c0;
	}

IL_01b4:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:285>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25522));
		bool L_72 = V_0;
		bool L_73 = V_1;
		V_26 = (bool)((int32_t)((int32_t)L_72&(int32_t)L_73));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25523));
		bool L_74 = V_26;
		if (!L_74)
		{
			goto IL_01c0;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:286>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25524));
		V_10 = (bool)1;
	}

IL_01c0:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:287>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25525));
		goto IL_01c2;
	}

IL_01c2:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:290>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25526));
		int32_t L_75 = V_3;
		int32_t L_76 = V_4;
		bool L_77 = V_10;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		StrBoolArray_SetBit_m212C6D1A8A4C422AF979D6B3BC7CD5B9BD0F3F01((&V_2), L_75, L_76, L_77, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25527));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25528));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25529));
		int32_t L_78 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_78, 1));
	}

IL_01d6:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:236>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25530));
		int32_t L_79 = V_4;
		int32_t L_80 = ___4_len;
		V_27 = (bool)((((int32_t)L_79) < ((int32_t)L_80))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25531));
		bool L_81 = V_27;
		if (L_81)
		{
			goto IL_003d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25532));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25533));
		int32_t L_82 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_82, 1));
	}

IL_01ea:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:228>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25534));
		int32_t L_83 = V_3;
		int32_t L_84 = ___4_len;
		V_28 = (bool)((((int32_t)L_83) < ((int32_t)L_84))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25535));
		bool L_85 = V_28;
		if (L_85)
		{
			goto IL_0014;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:294>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25536));
		V_6 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:297>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25537));
		int32_t L_86 = ___5_imm8;
		V_30 = ((int32_t)(((int32_t)(L_86>>2))&3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25538));
		int32_t L_87 = V_30;
		V_29 = L_87;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25539));
		int32_t L_88 = V_29;
		switch (L_88)
		{
			case 0:
			{
				goto IL_0223;
			}
			case 1:
			{
				goto IL_0270;
			}
			case 2:
			{
				goto IL_02cb;
			}
			case 3:
			{
				goto IL_02fb;
			}
		}
	}
	{
		goto IL_035a;
	}

IL_0223:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25540));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25541));
		goto IL_0260;
	}

IL_0227:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25542));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25543));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25544));
		goto IL_024f;
	}

IL_022d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25545));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:304>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25546));
		int32_t L_89 = V_6;
		int32_t L_90 = V_4;
		int32_t L_91 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		bool L_92;
		L_92 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_90, L_91, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25547));
		if (L_92)
		{
			G_B61_0 = L_89;
			goto IL_023f;
		}
		G_B60_0 = L_89;
	}
	{
		G_B62_0 = 0;
		G_B62_1 = G_B60_0;
		goto IL_0240;
	}

IL_023f:
	{
		G_B62_0 = 1;
		G_B62_1 = G_B61_0;
	}

IL_0240:
	{
		int32_t L_93 = V_3;
		V_6 = ((int32_t)(G_B62_1|((int32_t)(G_B62_0<<((int32_t)(L_93&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25548));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25549));
		int32_t L_94 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_94, 1));
	}

IL_024f:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:302>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25550));
		int32_t L_95 = V_4;
		int32_t L_96 = ___4_len;
		V_31 = (bool)((((int32_t)L_95) < ((int32_t)L_96))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25551));
		bool L_97 = V_31;
		if (L_97)
		{
			goto IL_022d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25552));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25553));
		int32_t L_98 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_98, 1));
	}

IL_0260:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:300>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25554));
		int32_t L_99 = V_3;
		int32_t L_100 = ___4_len;
		V_32 = (bool)((((int32_t)L_99) < ((int32_t)L_100))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25555));
		bool L_101 = V_32;
		if (L_101)
		{
			goto IL_0227;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:312>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25556));
		goto IL_035a;
	}

IL_0270:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25557));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25558));
		goto IL_02bb;
	}

IL_0274:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25559));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25560));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25561));
		goto IL_02aa;
	}

IL_027a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25562));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:318>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25563));
		int32_t L_102 = V_6;
		int32_t L_103 = V_4;
		int32_t L_104 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		bool L_105;
		L_105 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_103, L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25564));
		if (!L_105)
		{
			G_B71_0 = L_102;
			goto IL_0297;
		}
		G_B70_0 = L_102;
	}
	{
		int32_t L_106 = V_4;
		int32_t L_107 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		bool L_108;
		L_108 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), ((int32_t)il2cpp_codegen_add(L_106, 1)), L_107, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25565));
		if (L_108)
		{
			G_B72_0 = G_B70_0;
			goto IL_029a;
		}
		G_B71_0 = G_B70_0;
	}

IL_0297:
	{
		G_B73_0 = 0;
		G_B73_1 = G_B71_0;
		goto IL_029b;
	}

IL_029a:
	{
		G_B73_0 = 1;
		G_B73_1 = G_B72_0;
	}

IL_029b:
	{
		int32_t L_109 = V_3;
		V_6 = ((int32_t)(G_B73_1|((int32_t)(G_B73_0<<((int32_t)(L_109&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25566));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25567));
		int32_t L_110 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_110, 2));
	}

IL_02aa:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:316>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25568));
		int32_t L_111 = V_4;
		int32_t L_112 = ___4_len;
		V_33 = (bool)((((int32_t)L_111) < ((int32_t)L_112))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25569));
		bool L_113 = V_33;
		if (L_113)
		{
			goto IL_027a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25570));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25571));
		int32_t L_114 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_114, 1));
	}

IL_02bb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:314>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25572));
		int32_t L_115 = V_3;
		int32_t L_116 = ___4_len;
		V_34 = (bool)((((int32_t)L_115) < ((int32_t)L_116))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25573));
		bool L_117 = V_34;
		if (L_117)
		{
			goto IL_0274;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:321>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25574));
		goto IL_035a;
	}

IL_02cb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25575));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25576));
		goto IL_02ee;
	}

IL_02cf:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25577));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:325>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25578));
		int32_t L_118 = V_6;
		int32_t L_119 = V_3;
		int32_t L_120 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		bool L_121;
		L_121 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_119, L_120, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25579));
		if (L_121)
		{
			G_B81_0 = L_118;
			goto IL_02e0;
		}
		G_B80_0 = L_118;
	}
	{
		G_B82_0 = 0;
		G_B82_1 = G_B80_0;
		goto IL_02e1;
	}

IL_02e0:
	{
		G_B82_0 = 1;
		G_B82_1 = G_B81_0;
	}

IL_02e1:
	{
		int32_t L_122 = V_3;
		V_6 = ((int32_t)(G_B82_1|((int32_t)(G_B82_0<<((int32_t)(L_122&((int32_t)31)))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25580));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25581));
		int32_t L_123 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_123, 1));
	}

IL_02ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:323>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25582));
		int32_t L_124 = V_3;
		int32_t L_125 = ___4_len;
		V_35 = (bool)((((int32_t)L_124) < ((int32_t)L_125))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25583));
		bool L_126 = V_35;
		if (L_126)
		{
			goto IL_02cf;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:327>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25584));
		goto IL_035a;
	}

IL_02fb:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:329>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25585));
		int32_t L_127 = ___6_allOnes;
		V_6 = L_127;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25586));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25587));
		goto IL_034d;
	}

IL_0303:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25588));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:332>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25589));
		int32_t L_128 = V_3;
		V_36 = L_128;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25590));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25591));
		goto IL_033a;
	}

IL_030c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25592));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:335>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25593));
		int32_t L_129 = V_4;
		int32_t L_130 = V_36;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		bool L_131;
		L_131 = StrBoolArray_GetBit_mCA50A9F3A3FA5C552305C9B762264A6058F33E78((&V_2), L_129, L_130, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25594));
		V_37 = (bool)((((int32_t)L_131) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25595));
		bool L_132 = V_37;
		if (!L_132)
		{
			goto IL_032d;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:336>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25596));
		int32_t L_133 = V_6;
		int32_t L_134 = V_3;
		V_6 = ((int32_t)(L_133&((~((int32_t)(1<<((int32_t)(L_134&((int32_t)31)))))))));
	}

IL_032d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:337>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25597));
		int32_t L_135 = V_36;
		V_36 = ((int32_t)il2cpp_codegen_add(L_135, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25598));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25599));
		int32_t L_136 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_136, 1));
	}

IL_033a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:333>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25600));
		int32_t L_137 = V_4;
		int32_t L_138 = ___4_len;
		int32_t L_139 = V_3;
		V_38 = (bool)((((int32_t)L_137) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_138, L_139))))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25601));
		bool L_140 = V_38;
		if (L_140)
		{
			goto IL_030c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25602));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25603));
		int32_t L_141 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_141, 1));
	}

IL_034d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:330>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25604));
		int32_t L_142 = V_3;
		int32_t L_143 = ___4_len;
		V_39 = (bool)((((int32_t)L_142) < ((int32_t)L_143))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25605));
		bool L_144 = V_39;
		if (L_144)
		{
			goto IL_0303;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:340>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25606));
		goto IL_035a;
	}

IL_035a:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:343>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25607));
		V_5 = 0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:346>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25608));
		V_1 = (bool)0;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25609));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25610));
		goto IL_0401;
	}

IL_0366:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25611));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:349>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25612));
		int32_t L_145 = ___5_imm8;
		V_40 = (bool)((!(((uint32_t)((int32_t)(L_145&((int32_t)16)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25613));
		bool L_146 = V_40;
		if (!L_146)
		{
			goto IL_03ee;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25614));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:351>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25615));
		int32_t L_147 = ___5_imm8;
		V_41 = (bool)((!(((uint32_t)((int32_t)(L_147&((int32_t)32)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25616));
		bool L_148 = V_41;
		if (!L_148)
		{
			goto IL_03dc;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25617));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:353>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25618));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_149;
		L_149 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25619));
		Il2CppFullySharedGenericStruct* L_150 = ___2_b;
		int32_t L_151 = V_3;
		uint32_t L_152 = SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77;
		il2cpp_codegen_memcpy(L_153, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_150, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_151), (int32_t)L_152)))), SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_43, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		il2cpp_codegen_memcpy(L_154, V_43, SizeOf_T_t7F8E2A189F579B2C727588D60559F5E6306C2E77);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		NullCheck(L_149);
		bool L_155;
		L_155 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_149, L_153, L_154);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25620));
		V_42 = L_155;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25621));
		bool L_156 = V_42;
		if (!L_156)
		{
			goto IL_03b3;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25622));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:355>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25623));
		V_1 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25624));
	}

IL_03b3:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:358>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25625));
		bool L_157 = V_1;
		V_44 = L_157;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25626));
		bool L_158 = V_44;
		if (!L_158)
		{
			goto IL_03ca;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:359>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25627));
		int32_t L_159 = V_5;
		int32_t L_160 = V_6;
		int32_t L_161 = V_3;
		V_5 = ((int32_t)(L_159|((int32_t)(L_160&((int32_t)(1<<((int32_t)(L_161&((int32_t)31)))))))));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25628));
		goto IL_03d9;
	}

IL_03ca:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:361>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25629));
		int32_t L_162 = V_5;
		int32_t L_163 = V_6;
		int32_t L_164 = V_3;
		V_5 = ((int32_t)(L_162|((int32_t)(((~L_163))&((int32_t)(1<<((int32_t)(L_164&((int32_t)31)))))))));
	}

IL_03d9:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25630));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25631));
		goto IL_03eb;
	}

IL_03dc:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:364>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25632));
		int32_t L_165 = V_5;
		int32_t L_166 = V_6;
		int32_t L_167 = V_3;
		V_5 = ((int32_t)(L_165|((int32_t)(((~L_166))&((int32_t)(1<<((int32_t)(L_167&((int32_t)31)))))))));
	}

IL_03eb:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25633));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25634));
		goto IL_03fc;
	}

IL_03ee:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:367>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25635));
		int32_t L_168 = V_5;
		int32_t L_169 = V_6;
		int32_t L_170 = V_3;
		V_5 = ((int32_t)(L_168|((int32_t)(L_169&((int32_t)(1<<((int32_t)(L_170&((int32_t)31)))))))));
	}

IL_03fc:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25636));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25637));
		int32_t L_171 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_171, 1));
	}

IL_0401:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:347>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25638));
		int32_t L_172 = V_3;
		int32_t L_173 = ___4_len;
		V_45 = (bool)((((int32_t)L_172) < ((int32_t)L_173))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25639));
		bool L_174 = V_45;
		if (L_174)
		{
			goto IL_0366;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:370>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25640));
		int32_t L_175 = V_5;
		V_46 = L_175;
		goto IL_0415;
	}

IL_0415:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:374>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25641));
		int32_t L_176 = V_46;
		return L_176;
	}
}
// Method Definition Index: 117201
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A_gshared (uint8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	bool V_1 = false;
	uint8_t V_2 = 0x0;
	int32_t V_3 = 0;
	bool V_4 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_ptr), (&___1_max));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25418));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25419));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25420));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25421));
		V_0 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25422));
		goto IL_0037;
	}

IL_0005:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25423));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25424));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_0;
		L_0 = EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		uint8_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(uint8_t);
		uint8_t L_4 = (*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_2), sizeof(uint8_t));
		uint8_t L_5 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, uint8_t, uint8_t >::Invoke(8, L_0, L_4, L_5);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		V_1 = L_6;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25427));
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0032;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25428));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25429));
		int32_t L_8 = V_0;
		V_3 = L_8;
		goto IL_0045;
	}

IL_0032:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25430));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25431));
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0037:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25432));
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_max;
		V_4 = (bool)((((int32_t)L_10) < ((int32_t)L_11))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25433));
		bool L_12 = V_4;
		if (L_12)
		{
			goto IL_0005;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25434));
		int32_t L_13 = ___1_max;
		V_3 = L_13;
		goto IL_0045;
	}

IL_0045:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:218>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25435));
		int32_t L_14 = V_3;
		return L_14;
	}
}
// Method Definition Index: 117201
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3_gshared (int16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	bool V_1 = false;
	int16_t V_2 = 0;
	int32_t V_3 = 0;
	bool V_4 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_ptr), (&___1_max));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25418));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25419));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25420));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25421));
		V_0 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25422));
		goto IL_0037;
	}

IL_0005:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25423));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25424));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_0;
		L_0 = EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		int16_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(int16_t);
		int16_t L_4 = (*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_2), sizeof(int16_t));
		int16_t L_5 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, int16_t, int16_t >::Invoke(8, L_0, L_4, L_5);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		V_1 = L_6;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25427));
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0032;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25428));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25429));
		int32_t L_8 = V_0;
		V_3 = L_8;
		goto IL_0045;
	}

IL_0032:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25430));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25431));
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0037:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25432));
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_max;
		V_4 = (bool)((((int32_t)L_10) < ((int32_t)L_11))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25433));
		bool L_12 = V_4;
		if (L_12)
		{
			goto IL_0005;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25434));
		int32_t L_13 = ___1_max;
		V_3 = L_13;
		goto IL_0045;
	}

IL_0045:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:218>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25435));
		int32_t L_14 = V_3;
		return L_14;
	}
}
// Method Definition Index: 117201
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171_gshared (int8_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	bool V_1 = false;
	int8_t V_2 = 0x0;
	int32_t V_3 = 0;
	bool V_4 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_ptr), (&___1_max));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25418));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25419));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25420));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25421));
		V_0 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25422));
		goto IL_0037;
	}

IL_0005:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25423));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25424));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_0;
		L_0 = EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		int8_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(int8_t);
		int8_t L_4 = (*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_2), sizeof(int8_t));
		int8_t L_5 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, int8_t, int8_t >::Invoke(8, L_0, L_4, L_5);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		V_1 = L_6;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25427));
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0032;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25428));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25429));
		int32_t L_8 = V_0;
		V_3 = L_8;
		goto IL_0045;
	}

IL_0032:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25430));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25431));
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0037:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25432));
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_max;
		V_4 = (bool)((((int32_t)L_10) < ((int32_t)L_11))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25433));
		bool L_12 = V_4;
		if (L_12)
		{
			goto IL_0005;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25434));
		int32_t L_13 = ___1_max;
		V_3 = L_13;
		goto IL_0045;
	}

IL_0045:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:218>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25435));
		int32_t L_14 = V_3;
		return L_14;
	}
}
// Method Definition Index: 117201
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D_gshared (uint16_t* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	bool V_1 = false;
	uint16_t V_2 = 0;
	int32_t V_3 = 0;
	bool V_4 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_ptr), (&___1_max));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25418));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25419));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25420));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25421));
		V_0 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25422));
		goto IL_0037;
	}

IL_0005:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25423));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25424));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_0;
		L_0 = EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_inline(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		uint16_t* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = sizeof(uint16_t);
		uint16_t L_4 = (*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		il2cpp_codegen_initobj((&V_2), sizeof(uint16_t));
		uint16_t L_5 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2< bool, uint16_t, uint16_t >::Invoke(8, L_0, L_4, L_5);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		V_1 = L_6;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25427));
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0032;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25428));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25429));
		int32_t L_8 = V_0;
		V_3 = L_8;
		goto IL_0045;
	}

IL_0032:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25430));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25431));
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0037:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25432));
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_max;
		V_4 = (bool)((((int32_t)L_10) < ((int32_t)L_11))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25433));
		bool L_12 = V_4;
		if (L_12)
		{
			goto IL_0005;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25434));
		int32_t L_13 = ___1_max;
		V_3 = L_13;
		goto IL_0045;
	}

IL_0045:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:218>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25435));
		int32_t L_14 = V_3;
		return L_14;
	}
}
// Method Definition Index: 117201
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_ComputeStringLength_TisIl2CppFullySharedGenericStruct_m764CDB4D47CB1C77EAA40D60D44F53C4E97CD8D6_gshared (Il2CppFullySharedGenericStruct* ___0_ptr, int32_t ___1_max, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 4));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	const Il2CppFullySharedGenericStruct L_5 = alloca(SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	int32_t V_0 = 0;
	bool V_1 = false;
	Il2CppFullySharedGenericStruct V_2 = alloca(SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	memset(V_2, 0, SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
	int32_t V_3 = 0;
	bool V_4 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_ptr), (&___1_max));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25418));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25419));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25420));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25421));
		V_0 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25422));
		goto IL_0037;
	}

IL_0005:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25423));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:212>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25424));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* L_0;
		L_0 = ((  EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25425));
		Il2CppFullySharedGenericStruct* L_1 = ___0_ptr;
		int32_t L_2 = V_0;
		uint32_t L_3 = SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64;
		il2cpp_codegen_memcpy(L_4, ((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))), SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericStruct*)V_2, SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
		il2cpp_codegen_memcpy(L_5, V_2, SizeOf_T_t2125B686AA2A4D4755B95692CBE3C48B69824C64);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		NullCheck(L_0);
		bool L_6;
		L_6 = VirtualFuncInvoker2Invoker< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(8, L_0, L_4, L_5);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25426));
		V_1 = L_6;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25427));
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0032;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25428));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:214>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25429));
		int32_t L_8 = V_0;
		V_3 = L_8;
		goto IL_0045;
	}

IL_0032:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25430));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25431));
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0037:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:210>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25432));
		int32_t L_10 = V_0;
		int32_t L_11 = ___1_max;
		V_4 = (bool)((((int32_t)L_10) < ((int32_t)L_11))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25433));
		bool L_12 = V_4;
		if (L_12)
		{
			goto IL_0005;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:217>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25434));
		int32_t L_13 = ___1_max;
		V_3 = L_13;
		goto IL_0045;
	}

IL_0045:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:218>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25435));
		int32_t L_14 = V_3;
		return L_14;
	}
}
// Method Definition Index: 117197
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235_gshared (int32_t ___0_len, int32_t ___1_imm8, uint8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_6;
	memset((&V_6), 0, sizeof(V_6));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_len), (&___1_imm8), (&___2_allOnesT), (&___3_intRes2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_2), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25337));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25338));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25339));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25340));
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25341));
		int32_t L_0 = ___1_imm8;
		V_1 = (bool)((!(((uint32_t)((int32_t)(L_0&((int32_t)64)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25342));
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_006e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25344));
		uint8_t* L_2 = (uint8_t*)(&(&V_0)->___Byte0);
		V_2 = (uint8_t*)((uintptr_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25345));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25346));
		goto IL_0061;
	}

IL_0022:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25347));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25348));
		int32_t L_3 = ___3_intRes2;
		int32_t L_4 = V_3;
		V_4 = (bool)((!(((uint32_t)((int32_t)(L_3&((int32_t)(1<<((int32_t)(L_4&((int32_t)31)))))))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25349));
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_0049;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25350));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25351));
		uint8_t* L_6 = V_2;
		int32_t L_7 = V_3;
		uint32_t L_8 = sizeof(uint8_t);
		uint8_t L_9 = ___2_allOnesT;
		*(uint8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))) = L_9;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25352));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25353));
		goto IL_005c;
	}

IL_0049:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25354));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25355));
		uint8_t* L_10 = V_2;
		int32_t L_11 = V_3;
		uint32_t L_12 = sizeof(uint8_t);
		il2cpp_codegen_initobj(((uint8_t*)il2cpp_codegen_add((intptr_t)L_10, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_11), (int32_t)L_12)))), sizeof(uint8_t));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25356));
	}

IL_005c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25357));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25358));
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0061:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25359));
		int32_t L_14 = V_3;
		int32_t L_15 = ___0_len;
		V_5 = (bool)((((int32_t)L_14) < ((int32_t)L_15))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25360));
		bool L_16 = V_5;
		if (L_16)
		{
			goto IL_0022;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25361));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25362));
		goto IL_0078;
	}

IL_006e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25363));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25364));
		int32_t L_17 = ___3_intRes2;
		(&V_0)->___SInt0 = L_17;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25365));
	}

IL_0078:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25366));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_18 = V_0;
		V_6 = L_18;
		goto IL_007d;
	}

IL_007d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:165>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25367));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_19 = V_6;
		return L_19;
	}
}
// Method Definition Index: 117197
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8_gshared (int32_t ___0_len, int32_t ___1_imm8, int16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	int16_t* V_2 = NULL;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_6;
	memset((&V_6), 0, sizeof(V_6));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_len), (&___1_imm8), (&___2_allOnesT), (&___3_intRes2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_2), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25337));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25338));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25339));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25340));
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25341));
		int32_t L_0 = ___1_imm8;
		V_1 = (bool)((!(((uint32_t)((int32_t)(L_0&((int32_t)64)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25342));
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_006e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25344));
		uint8_t* L_2 = (uint8_t*)(&(&V_0)->___Byte0);
		V_2 = (int16_t*)((uintptr_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25345));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25346));
		goto IL_0061;
	}

IL_0022:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25347));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25348));
		int32_t L_3 = ___3_intRes2;
		int32_t L_4 = V_3;
		V_4 = (bool)((!(((uint32_t)((int32_t)(L_3&((int32_t)(1<<((int32_t)(L_4&((int32_t)31)))))))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25349));
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_0049;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25350));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25351));
		int16_t* L_6 = V_2;
		int32_t L_7 = V_3;
		uint32_t L_8 = sizeof(int16_t);
		int16_t L_9 = ___2_allOnesT;
		*(int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))) = L_9;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25352));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25353));
		goto IL_005c;
	}

IL_0049:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25354));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25355));
		int16_t* L_10 = V_2;
		int32_t L_11 = V_3;
		uint32_t L_12 = sizeof(int16_t);
		il2cpp_codegen_initobj(((int16_t*)il2cpp_codegen_add((intptr_t)L_10, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_11), (int32_t)L_12)))), sizeof(int16_t));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25356));
	}

IL_005c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25357));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25358));
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0061:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25359));
		int32_t L_14 = V_3;
		int32_t L_15 = ___0_len;
		V_5 = (bool)((((int32_t)L_14) < ((int32_t)L_15))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25360));
		bool L_16 = V_5;
		if (L_16)
		{
			goto IL_0022;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25361));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25362));
		goto IL_0078;
	}

IL_006e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25363));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25364));
		int32_t L_17 = ___3_intRes2;
		(&V_0)->___SInt0 = L_17;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25365));
	}

IL_0078:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25366));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_18 = V_0;
		V_6 = L_18;
		goto IL_007d;
	}

IL_007d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:165>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25367));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_19 = V_6;
		return L_19;
	}
}
// Method Definition Index: 117197
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455_gshared (int32_t ___0_len, int32_t ___1_imm8, int8_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	int8_t* V_2 = NULL;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_6;
	memset((&V_6), 0, sizeof(V_6));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_len), (&___1_imm8), (&___2_allOnesT), (&___3_intRes2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_2), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25337));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25338));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25339));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25340));
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25341));
		int32_t L_0 = ___1_imm8;
		V_1 = (bool)((!(((uint32_t)((int32_t)(L_0&((int32_t)64)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25342));
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_006e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25344));
		uint8_t* L_2 = (uint8_t*)(&(&V_0)->___Byte0);
		V_2 = (int8_t*)((uintptr_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25345));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25346));
		goto IL_0061;
	}

IL_0022:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25347));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25348));
		int32_t L_3 = ___3_intRes2;
		int32_t L_4 = V_3;
		V_4 = (bool)((!(((uint32_t)((int32_t)(L_3&((int32_t)(1<<((int32_t)(L_4&((int32_t)31)))))))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25349));
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_0049;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25350));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25351));
		int8_t* L_6 = V_2;
		int32_t L_7 = V_3;
		uint32_t L_8 = sizeof(int8_t);
		int8_t L_9 = ___2_allOnesT;
		*(int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))) = L_9;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25352));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25353));
		goto IL_005c;
	}

IL_0049:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25354));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25355));
		int8_t* L_10 = V_2;
		int32_t L_11 = V_3;
		uint32_t L_12 = sizeof(int8_t);
		il2cpp_codegen_initobj(((int8_t*)il2cpp_codegen_add((intptr_t)L_10, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_11), (int32_t)L_12)))), sizeof(int8_t));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25356));
	}

IL_005c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25357));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25358));
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0061:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25359));
		int32_t L_14 = V_3;
		int32_t L_15 = ___0_len;
		V_5 = (bool)((((int32_t)L_14) < ((int32_t)L_15))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25360));
		bool L_16 = V_5;
		if (L_16)
		{
			goto IL_0022;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25361));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25362));
		goto IL_0078;
	}

IL_006e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25363));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25364));
		int32_t L_17 = ___3_intRes2;
		(&V_0)->___SInt0 = L_17;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25365));
	}

IL_0078:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25366));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_18 = V_0;
		V_6 = L_18;
		goto IL_007d;
	}

IL_007d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:165>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25367));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_19 = V_6;
		return L_19;
	}
}
// Method Definition Index: 117197
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1_gshared (int32_t ___0_len, int32_t ___1_imm8, uint16_t ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	uint16_t* V_2 = NULL;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_6;
	memset((&V_6), 0, sizeof(V_6));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_len), (&___1_imm8), (&___2_allOnesT), (&___3_intRes2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_2), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25337));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25338));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25339));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25340));
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25341));
		int32_t L_0 = ___1_imm8;
		V_1 = (bool)((!(((uint32_t)((int32_t)(L_0&((int32_t)64)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25342));
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_006e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25344));
		uint8_t* L_2 = (uint8_t*)(&(&V_0)->___Byte0);
		V_2 = (uint16_t*)((uintptr_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25345));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25346));
		goto IL_0061;
	}

IL_0022:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25347));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25348));
		int32_t L_3 = ___3_intRes2;
		int32_t L_4 = V_3;
		V_4 = (bool)((!(((uint32_t)((int32_t)(L_3&((int32_t)(1<<((int32_t)(L_4&((int32_t)31)))))))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25349));
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_0049;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25350));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25351));
		uint16_t* L_6 = V_2;
		int32_t L_7 = V_3;
		uint32_t L_8 = sizeof(uint16_t);
		uint16_t L_9 = ___2_allOnesT;
		*(uint16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))) = L_9;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25352));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25353));
		goto IL_005c;
	}

IL_0049:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25354));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25355));
		uint16_t* L_10 = V_2;
		int32_t L_11 = V_3;
		uint32_t L_12 = sizeof(uint16_t);
		il2cpp_codegen_initobj(((uint16_t*)il2cpp_codegen_add((intptr_t)L_10, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_11), (int32_t)L_12)))), sizeof(uint16_t));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25356));
	}

IL_005c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25357));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25358));
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0061:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25359));
		int32_t L_14 = V_3;
		int32_t L_15 = ___0_len;
		V_5 = (bool)((((int32_t)L_14) < ((int32_t)L_15))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25360));
		bool L_16 = V_5;
		if (L_16)
		{
			goto IL_0022;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25361));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25362));
		goto IL_0078;
	}

IL_006e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25363));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25364));
		int32_t L_17 = ___3_intRes2;
		(&V_0)->___SInt0 = L_17;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25365));
	}

IL_0078:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25366));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_18 = V_0;
		V_6 = L_18;
		goto IL_007d;
	}

IL_007d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:165>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25367));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_19 = V_6;
		return L_19;
	}
}
// Method Definition Index: 117197
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_ComputeStrmOutput_TisIl2CppFullySharedGenericStruct_m64ADE71FB4B90FEC60799387186E249935DE041C_gshared (int32_t ___0_len, int32_t ___1_imm8, Il2CppFullySharedGenericStruct ___2_allOnesT, int32_t ___3_intRes2, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_9 = alloca(SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	Il2CppFullySharedGenericStruct* V_2 = NULL;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_6;
	memset((&V_6), 0, sizeof(V_6));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_len), (&___1_imm8), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 0)) ? ___2_allOnesT : &___2_allOnesT), (&___3_intRes2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_2), (&V_3));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25337));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25338));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25339));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:141>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25340));
		il2cpp_codegen_initobj((&V_0), sizeof(v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:142>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25341));
		int32_t L_0 = ___1_imm8;
		V_1 = (bool)((!(((uint32_t)((int32_t)(L_0&((int32_t)64)))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25342));
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_006e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25343));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:145>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25344));
		uint8_t* L_2 = (uint8_t*)(&(&V_0)->___Byte0);
		V_2 = (Il2CppFullySharedGenericStruct*)((uintptr_t)L_2);
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25345));
		V_3 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25346));
		goto IL_0061;
	}

IL_0022:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25347));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25348));
		int32_t L_3 = ___3_intRes2;
		int32_t L_4 = V_3;
		V_4 = (bool)((!(((uint32_t)((int32_t)(L_3&((int32_t)(1<<((int32_t)(L_4&((int32_t)31)))))))) <= ((uint32_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25349));
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_0049;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25350));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:150>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25351));
		Il2CppFullySharedGenericStruct* L_6 = V_2;
		int32_t L_7 = V_3;
		uint32_t L_8 = SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B;
		il2cpp_codegen_memcpy(L_9, ___2_allOnesT, SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))), L_9, SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_6, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_7), (int32_t)L_8)))), (void*)L_9);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25352));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25353));
		goto IL_005c;
	}

IL_0049:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25354));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25355));
		Il2CppFullySharedGenericStruct* L_10 = V_2;
		int32_t L_11 = V_3;
		uint32_t L_12 = SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B;
		il2cpp_codegen_initobj(((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_10, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_11), (int32_t)L_12)))), SizeOf_T_t4AB7E7218B07206B6D97D6E91CAC0F37510C246B);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25356));
	}

IL_005c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25357));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25358));
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0061:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25359));
		int32_t L_14 = V_3;
		int32_t L_15 = ___0_len;
		V_5 = (bool)((((int32_t)L_14) < ((int32_t)L_15))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25360));
		bool L_16 = V_5;
		if (L_16)
		{
			goto IL_0022;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25361));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25362));
		goto IL_0078;
	}

IL_006e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25363));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:161>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25364));
		int32_t L_17 = ___3_intRes2;
		(&V_0)->___SInt0 = L_17;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25365));
	}

IL_0078:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:164>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25366));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_18 = V_0;
		V_6 = L_18;
		goto IL_007d;
	}

IL_007d:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:165>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25367));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_19 = V_6;
		return L_19;
	}
}
// Method Definition Index: 117199
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD4107C2F2DB7508841779CE414BD21B61FA3183F_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25378));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25379));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25380));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25381));
		uint8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25383));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		V_1 = L_11;
		goto IL_001e;
	}

IL_001e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:179>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25385));
		int32_t L_12 = V_1;
		return L_12;
	}
}
// Method Definition Index: 117199
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m797C4B561EC2527267C18CF422EBBD9FCDD306EF_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25378));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25379));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25380));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25381));
		int16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25383));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		V_1 = L_11;
		goto IL_001e;
	}

IL_001e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:179>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25385));
		int32_t L_12 = V_1;
		return L_12;
	}
}
// Method Definition Index: 117199
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m8934296ABE51C76314606C484F93554C529BD77A_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25378));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25379));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25380));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25381));
		int8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25383));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		V_1 = L_11;
		goto IL_001e;
	}

IL_001e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:179>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25385));
		int32_t L_12 = V_1;
		return L_12;
	}
}
// Method Definition Index: 117199
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m6A20624B95FD608D46A450719A26FC173F4C0780_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25378));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25379));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25380));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25381));
		uint16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25383));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		V_1 = L_11;
		goto IL_001e;
	}

IL_001e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:179>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25385));
		int32_t L_12 = V_1;
		return L_12;
	}
}
// Method Definition Index: 117199
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpestri_emulation_TisIl2CppFullySharedGenericStruct_m92A1CC07F00E8D1EFF164A7AAA2CEF3A90BC8071_gshared (Il2CppFullySharedGenericStruct* ___0_a, int32_t ___1_alen, Il2CppFullySharedGenericStruct* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, Il2CppFullySharedGenericStruct ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 2)) ? ___7_allOnesT : &___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25378));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25379));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25380));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:176>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25381));
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		Il2CppFullySharedGenericStruct* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25382));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:178>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25383));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int32_t L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_8, L_9, L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25384));
		V_1 = L_11;
		goto IL_001e;
	}

IL_001e:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:179>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25385));
		int32_t L_12 = V_1;
		return L_12;
	}
}
// Method Definition Index: 117196
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m179C750FBD381FF2897A9140CF7C2661939C7E71_gshared (uint8_t* ___0_a, int32_t ___1_alen, uint8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25329));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25330));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25331));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25332));
		uint8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25334));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		uint8_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		V_1 = L_12;
		goto IL_0020;
	}

IL_0020:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:136>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25336));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_13 = V_1;
		return L_13;
	}
}
// Method Definition Index: 117196
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m9F860C6A223CB8744EB0C859B49E573C300C9F7B_gshared (int16_t* ___0_a, int32_t ___1_alen, int16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25329));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25330));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25331));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25332));
		int16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25334));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int16_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		V_1 = L_12;
		goto IL_0020;
	}

IL_0020:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:136>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25336));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_13 = V_1;
		return L_13;
	}
}
// Method Definition Index: 117196
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mEC9DD6EE9C8D66BCFFABD5A19993FDA06444F20C_gshared (int8_t* ___0_a, int32_t ___1_alen, int8_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, int8_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25329));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25330));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25331));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25332));
		int8_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		int8_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25334));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		int8_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		V_1 = L_12;
		goto IL_0020;
	}

IL_0020:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:136>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25336));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_13 = V_1;
		return L_13;
	}
}
// Method Definition Index: 117196
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m8784D19FC1B4BAC48D00E8623FE1872EFEFD3496_gshared (uint16_t* ___0_a, int32_t ___1_alen, uint16_t* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, uint16_t ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (&___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25329));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25330));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25331));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25332));
		uint16_t* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		uint16_t* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25334));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		uint16_t L_10 = ___7_allOnesT;
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1(L_8, L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		V_1 = L_12;
		goto IL_0020;
	}

IL_0020:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:136>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25336));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_13 = V_1;
		return L_13;
	}
}
// Method Definition Index: 117196
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpestrm_emulation_TisIl2CppFullySharedGenericStruct_m81548202F0BF107992042F154D34BCB0C7366524_gshared (Il2CppFullySharedGenericStruct* ___0_a, int32_t ___1_alen, Il2CppFullySharedGenericStruct* ___2_b, int32_t ___3_blen, int32_t ___4_len, int32_t ___5_imm8, int32_t ___6_allOnes, Il2CppFullySharedGenericStruct ___7_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t42FC5CD236BFE90D4A941BFCE621367A7EA03BDC = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericStruct L_10 = alloca(SizeOf_T_t42FC5CD236BFE90D4A941BFCE621367A7EA03BDC);
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_alen), (&___2_b), (&___3_blen), (&___4_len), (&___5_imm8), (&___6_allOnes), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 2)) ? ___7_allOnesT : &___7_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25329));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25330));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25331));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:133>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25332));
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		int32_t L_1 = ___1_alen;
		Il2CppFullySharedGenericStruct* L_2 = ___2_b;
		int32_t L_3 = ___3_blen;
		int32_t L_4 = ___4_len;
		int32_t L_5 = ___5_imm8;
		int32_t L_6 = ___6_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, L_1, L_2, L_3, L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25333));
		V_0 = L_7;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:135>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25334));
		int32_t L_8 = ___4_len;
		int32_t L_9 = ___5_imm8;
		il2cpp_codegen_memcpy(L_10, ___7_allOnesT, SizeOf_T_t42FC5CD236BFE90D4A941BFCE621367A7EA03BDC);
		int32_t L_11 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_12;
		L_12 = InvokerFuncInvoker4< v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61, int32_t, int32_t, Il2CppFullySharedGenericStruct, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), NULL, L_8, L_9, L_10, L_11);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25335));
		V_1 = L_12;
		goto IL_0020;
	}

IL_0020:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:136>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25336));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_13 = V_1;
		return L_13;
	}
}
// Method Definition Index: 117198
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m2E6D2FDB31E3BFDFC30BDD2389A5A50C0F3286BB_gshared (uint8_t* ___0_a, uint8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25368));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25369));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25370));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25371));
		uint8_t* L_0 = ___0_a;
		uint8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		uint8_t* L_4 = ___1_b;
		uint8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25375));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		V_1 = L_15;
		goto IL_0026;
	}

IL_0026:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:172>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25377));
		int32_t L_16 = V_1;
		return L_16;
	}
}
// Method Definition Index: 117198
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m4786E128EACDF39A8B13B696D31429E7C8D6EBF6_gshared (int16_t* ___0_a, int16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25368));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25369));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25370));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25371));
		int16_t* L_0 = ___0_a;
		int16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		int16_t* L_4 = ___1_b;
		int16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25375));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		V_1 = L_15;
		goto IL_0026;
	}

IL_0026:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:172>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25377));
		int32_t L_16 = V_1;
		return L_16;
	}
}
// Method Definition Index: 117198
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m12535D1A7206DB4C56C55B642E9F5F0B072810A3_gshared (int8_t* ___0_a, int8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25368));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25369));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25370));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25371));
		int8_t* L_0 = ___0_a;
		int8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		int8_t* L_4 = ___1_b;
		int8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25375));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		V_1 = L_15;
		goto IL_0026;
	}

IL_0026:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:172>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25377));
		int32_t L_16 = V_1;
		return L_16;
	}
}
// Method Definition Index: 117198
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m875686166B80F44B2A7B5837256932C7A6560E7D_gshared (uint16_t* ___0_a, uint16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25368));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25369));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25370));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25371));
		uint16_t* L_0 = ___0_a;
		uint16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		uint16_t* L_4 = ___1_b;
		uint16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25375));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		V_1 = L_15;
		goto IL_0026;
	}

IL_0026:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:172>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25377));
		int32_t L_16 = V_1;
		return L_16;
	}
}
// Method Definition Index: 117198
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sse4_2_cmpistri_emulation_TisIl2CppFullySharedGenericStruct_m0723D40FF7E3DA850D8AF6948CB6C949F855583D_gshared (Il2CppFullySharedGenericStruct* ___0_a, Il2CppFullySharedGenericStruct* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, Il2CppFullySharedGenericStruct ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 3)) ? ___5_allOnesT : &___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25368));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25369));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25370));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:169>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25371));
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		Il2CppFullySharedGenericStruct* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25372));
		Il2CppFullySharedGenericStruct* L_4 = ___1_b;
		Il2CppFullySharedGenericStruct* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25373));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		int32_t L_11;
		L_11 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25374));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:171>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25375));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int32_t L_14 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		int32_t L_15;
		L_15 = Sse4_2_ComputeStriOutput_mC9EFEB2A2B9B95760CEE913DF4EF7F57BE662123(L_12, L_13, L_14, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25376));
		V_1 = L_15;
		goto IL_0026;
	}

IL_0026:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:172>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25377));
		int32_t L_16 = V_1;
		return L_16;
	}
}
// Method Definition Index: 117195
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1E1CCF579BEBAD09719E3B27BCAB1A607CED8C89_gshared (uint8_t* ___0_a, uint8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25319));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25320));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25321));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25322));
		uint8_t* L_0 = ___0_a;
		uint8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		uint8_t* L_4 = ___1_b;
		uint8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mD30812062AA4852D166ABCDF3D79FDD1856F173A(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5D9BE946098FA4C7FC8CC23DEE63A0877E8D6C8B(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25326));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		uint8_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1CC4D51DF3F513318DCC288B066D0018EAF9C235(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		V_1 = L_16;
		goto IL_0028;
	}

IL_0028:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:129>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25328));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_17 = V_1;
		return L_17;
	}
}
// Method Definition Index: 117195
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m31A82E20D7EB7CDFCDF7EEA3E75BA4F38F8501D4_gshared (int16_t* ___0_a, int16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25319));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25320));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25321));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25322));
		int16_t* L_0 = ___0_a;
		int16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		int16_t* L_4 = ___1_b;
		int16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m3EBC75C6F39A7B1A5F62D88877C87C9F3B5617A3(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mB3F9377B1A57D35D5514DEF77B3D9279A8622960(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25326));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int16_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE92FFA321425E5808CD20616DC308BA7B36886E8(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		V_1 = L_16;
		goto IL_0028;
	}

IL_0028:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:129>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25328));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_17 = V_1;
		return L_17;
	}
}
// Method Definition Index: 117195
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mEA9E446133608807E4CF1C806055621BECFD93CF_gshared (int8_t* ___0_a, int8_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, int8_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25319));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25320));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25321));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25322));
		int8_t* L_0 = ___0_a;
		int8_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		int8_t* L_4 = ___1_b;
		int8_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m73215CC1A28F076B0D2472385756C7AF58CBA171(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mA23FD3A0C3B4448E4721DA31DA7B4B93A636A3FD(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25326));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		int8_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_m5EFDDE5126FDB6BF9F9ED55B39751B517522C455(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		V_1 = L_16;
		goto IL_0028;
	}

IL_0028:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:129>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25328));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_17 = V_1;
		return L_17;
	}
}
// Method Definition Index: 117195
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m084B5A607615E44BC1926F6FF9CF11754A074B06_gshared (uint16_t* ___0_a, uint16_t* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, uint16_t ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (&___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25319));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25320));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25321));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25322));
		uint16_t* L_0 = ___0_a;
		uint16_t* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		uint16_t* L_4 = ___1_b;
		uint16_t* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_7;
		L_7 = Sse4_2_ComputeStringLength_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m000E8D7B908376D69E48EACF3E6811C4DEE7A05D(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		int32_t L_11;
		L_11 = Sse4_2_ComputeStrCmpIntRes2_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m331D979D640CF9DF04C505875F9FB702E217B2AB(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25326));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		uint16_t L_14 = ___5_allOnesT;
		int32_t L_15 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = Sse4_2_ComputeStrmOutput_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mD44F4B084A230ACD38B4FCF13923F8986AFF0AB1(L_12, L_13, L_14, L_15, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		V_1 = L_16;
		goto IL_0028;
	}

IL_0028:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:129>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25328));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_17 = V_1;
		return L_17;
	}
}
// Method Definition Index: 117195
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 Sse4_2_cmpistrm_emulation_TisIl2CppFullySharedGenericStruct_m16F77547DC1C2BE0F6959A4B639E1210EF674C66_gshared (Il2CppFullySharedGenericStruct* ___0_a, Il2CppFullySharedGenericStruct* ___1_b, int32_t ___2_len, int32_t ___3_imm8, int32_t ___4_allOnes, Il2CppFullySharedGenericStruct ___5_allOnesT, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_tC319464E6946647CC7BFD95709030A0B11A82E13 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 3));
	const Il2CppFullySharedGenericStruct L_14 = alloca(SizeOf_T_tC319464E6946647CC7BFD95709030A0B11A82E13);
	int32_t V_0 = 0;
	v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_a), (&___1_b), (&___2_len), (&___3_imm8), (&___4_allOnes), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 3)) ? ___5_allOnesT : &___5_allOnesT));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25319));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Burst + 25320));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25321));
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:126>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25322));
		Il2CppFullySharedGenericStruct* L_0 = ___0_a;
		Il2CppFullySharedGenericStruct* L_1 = ___0_a;
		int32_t L_2 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		il2cpp_codegen_runtime_class_init_inline(Sse4_2_t40477411E6B6B2D01F3B0EA9D1B0A6281833C37C_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25323));
		Il2CppFullySharedGenericStruct* L_4 = ___1_b;
		Il2CppFullySharedGenericStruct* L_5 = ___1_b;
		int32_t L_6 = ___2_len;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_7;
		L_7 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25324));
		int32_t L_8 = ___2_len;
		int32_t L_9 = ___3_imm8;
		int32_t L_10 = ___4_allOnes;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		int32_t L_11;
		L_11 = ((  int32_t (*) (Il2CppFullySharedGenericStruct*, int32_t, Il2CppFullySharedGenericStruct*, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_0, L_3, L_4, L_7, L_8, L_9, L_10, il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25325));
		V_0 = L_11;
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:128>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25326));
		int32_t L_12 = ___2_len;
		int32_t L_13 = ___3_imm8;
		il2cpp_codegen_memcpy(L_14, ___5_allOnesT, SizeOf_T_tC319464E6946647CC7BFD95709030A0B11A82E13);
		int32_t L_15 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_16;
		L_16 = InvokerFuncInvoker4< v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61, int32_t, int32_t, Il2CppFullySharedGenericStruct, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), NULL, L_12, L_13, L_14, L_15);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25327));
		V_1 = L_16;
		goto IL_0028;
	}

IL_0028:
	{
		//<source_info:./Library/PackageCache/com.unity.burst@973857688024/Runtime/Intrinsics/x86/Sse4_2.cs:129>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Burst + 25328));
		v128_t9D2F2BF6DCFF1D82BF38064CF157489E1E680B61 L_17 = V_1;
		return L_17;
	}
}
// Method Definition Index: 133257
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 AsyncConversion_GetData_TisIl2CppFullySharedGenericStruct_m55B782125B0D4D0B65C9018372619ED6941CDFDA_gshared (AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2_0_0_0_var);
		il2cpp_rgctx_method_init(method);
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	bool V_2 = false;
	bool V_3 = false;
	int32_t V_4 = 0;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 V_5;
	memset((&V_5), 0, sizeof(V_5));
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 V_6;
	memset((&V_6), 0, sizeof(V_6));
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_4), (&V_5));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11408));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11409));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11410));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:69>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11411));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11412));
		int32_t L_0;
		L_0 = AsyncConversion_get_status_mB3A873407AF4E202A39758599DCEE52BEC196E2A(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11412));
		V_2 = (bool)((((int32_t)((((int32_t)L_0) == ((int32_t)3))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11413));
		bool L_1 = V_2;
		if (!L_1)
		{
			goto IL_001c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:70>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11414));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11415));
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_2 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3E9DC9108B87A8D625803B99E31E1FF1628D278D)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11415));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_001c:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:74>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11416));
		Api_tAE210A8378E537AFD1FA4B99562229CE842377FB* L_3 = __this->___m_Api;
		int32_t L_4 = __this->___m_RequestId;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11417));
		NullCheck(L_3);
		bool L_5;
		L_5 = VirtualFuncInvoker3< bool, int32_t, intptr_t*, int32_t* >::Invoke(9, L_3, L_4, (&V_0), (&V_1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11417));
		V_3 = L_5;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11418));
		bool L_6 = V_3;
		if (!L_6)
		{
			goto IL_0055;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11419));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:76>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11420));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11421));
		int32_t L_7;
		L_7 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11421));
		V_4 = L_7;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:77>
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:78>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11422));
		intptr_t L_8 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11423));
		void* L_9;
		L_9 = IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF(L_8, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11423));
		int32_t L_10 = V_1;
		int32_t L_11 = V_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11424));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_12;
		L_12 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (void*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_9, ((int32_t)(L_10/L_11)), (int32_t)1, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11424));
		V_5 = L_12;
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:83>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11425));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_13 = V_5;
		V_6 = L_13;
		goto IL_0060;
	}

IL_0055:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:86>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11426));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11427));
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_14 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_14, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral8753E91E57F4AF26C69DF5B5A006924AF1E9F9C2)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11427));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_14, method);
	}

IL_0060:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/Textures/XRCpuImage/AsyncConversion.cs:87>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 11428));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_15 = V_6;
		return L_15;
	}
}
IL2CPP_EXTERN_C  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 AsyncConversion_GetData_TisIl2CppFullySharedGenericStruct_m55B782125B0D4D0B65C9018372619ED6941CDFDA_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<AsyncConversion_t559EB9321AFB2B096C619203286FEDC6868DE9C2*>(__this + _offset);
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 _returnValue;
	_returnValue = AsyncConversion_GetData_TisIl2CppFullySharedGenericStruct_m55B782125B0D4D0B65C9018372619ED6941CDFDA(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 132860
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Provider_CreateOrResizeNativeArrayIfNecessary_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_m3FF6126D31B18EF8F02A921B6EF41A436C07AB3E_gshared (int32_t ___0_length, int32_t ___1_allocator, NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* ___2_array, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool V_0 = false;
	bool V_1 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_length), (&___1_allocator), (&___2_array));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8975));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8976));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8977));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:144>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8978));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* L_0 = ___2_array;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8979));
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m478F812F31DEC928EC9D697C47C7E188CCA0010F_inline(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8979));
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8980));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0036;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8981));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8982));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* L_3 = ___2_array;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8983));
		int32_t L_4;
		L_4 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_3)->___m_Length);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8983));
		int32_t L_5 = ___0_length;
		V_1 = (bool)((((int32_t)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8984));
		bool L_6 = V_1;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8985));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8986));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* L_7 = ___2_array;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8987));
		NativeArray_1_Dispose_m78ECC3FE24D545255D9CFABB81FC34CA6CC2A4A7(L_7, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8987));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:149>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8988));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* L_8 = ___2_array;
		int32_t L_9 = ___0_length;
		int32_t L_10 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8989));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70 L_11;
		memset((&L_11), 0, sizeof(L_11));
		NativeArray_1__ctor_mFD9836AFB0757330727FED396E637FB060E30DF5((&L_11), L_9, L_10, (int32_t)1, il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8989));
		*(NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70*)L_8 = L_11;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8990));
	}

IL_0033:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8991));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8992));
		goto IL_0046;
	}

IL_0036:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8993));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8994));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* L_12 = ___2_array;
		int32_t L_13 = ___0_length;
		int32_t L_14 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8995));
		NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70 L_15;
		memset((&L_15), 0, sizeof(L_15));
		NativeArray_1__ctor_mFD9836AFB0757330727FED396E637FB060E30DF5((&L_15), L_13, L_14, (int32_t)1, il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8995));
		*(NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70*)L_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8996));
	}

IL_0046:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:156>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8997));
		return;
	}
}
// Method Definition Index: 132860
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Provider_CreateOrResizeNativeArrayIfNecessary_TisIl2CppFullySharedGenericStruct_mA59758011A49ED37FE547FB2E7C71E29DA35A08E_gshared (int32_t ___0_length, int32_t ___1_allocator, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___2_array, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool V_0 = false;
	bool V_1 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_length), (&___1_allocator), (&___2_array));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8975));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8976));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8977));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:144>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8978));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_0 = ___2_array;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8979));
		bool L_1;
		L_1 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8979));
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8980));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0036;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8981));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8982));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_3 = ___2_array;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8983));
		int32_t L_4;
		L_4 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_3, il2cpp_rgctx_method(method->rgctx_data, 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8983));
		int32_t L_5 = ___0_length;
		V_1 = (bool)((((int32_t)((((int32_t)L_4) == ((int32_t)L_5))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8984));
		bool L_6 = V_1;
		if (!L_6)
		{
			goto IL_0033;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8985));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:148>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8986));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_7 = ___2_array;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8987));
		((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(L_7, il2cpp_rgctx_method(method->rgctx_data, 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8987));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:149>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8988));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_8 = ___2_array;
		int32_t L_9 = ___0_length;
		int32_t L_10 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8989));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_11;
		memset((&L_11), 0, sizeof(L_11));
		NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1((&L_11), L_9, L_10, (int32_t)1, il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8989));
		*(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)L_8 = L_11;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8990));
	}

IL_0033:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8991));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8992));
		goto IL_0046;
	}

IL_0036:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8993));
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:154>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8994));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_12 = ___2_array;
		int32_t L_13 = ___0_length;
		int32_t L_14 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8995));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_15;
		memset((&L_15), 0, sizeof(L_15));
		NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1((&L_15), L_13, L_14, (int32_t)1, il2cpp_rgctx_method(method->rgctx_data, 6));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8995));
		*(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)L_12 = L_15;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8996));
	}

IL_0046:
	{
		//<source_info:./Library/PackageCache/com.unity.xr.arfoundation@758da01db0fe/Runtime/ARSubsystems/PlaneTracking/XRPlaneSubsystem.cs:156>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_XR_ARSubsystems + 8997));
		return;
	}
}
// Method Definition Index: 107127
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_gshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_input));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30594));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 30595));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30596));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/xxHash3.StreamingState.cs:145>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30597));
		Il2CppFullySharedGenericStruct* L_0 = ___0_input;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30598));
		void* L_1;
		L_1 = ((  void* (*) (Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30598));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30599));
		int32_t L_2;
		L_2 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30599));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30600));
		il2cpp_codegen_runtime_class_init_inline(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5(__this, L_1, L_2, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30600));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/xxHash3.StreamingState.cs:146>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 30601));
		return;
	}
}
IL2CPP_EXTERN_C  void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method)
{
	StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020*>(__this + _offset);
	StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D(_thisAdjusted, ___0_input, method);
}
// Method Definition Index: 106146
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Allocate_TisIl2CppFullySharedGenericStruct_m472C3AE183E3C768741B28481DD1F012013B13A6_gshared (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	Il2CppFullySharedGenericStruct* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_count), (&___1_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20533));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20534));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20535));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:103>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20536));
		int64_t L_0 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20537));
		Il2CppFullySharedGenericStruct* L_2;
		L_2 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((Il2CppFullySharedGenericStruct*)((uintptr_t)0), ((int64_t)0), L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20537));
		V_0 = L_2;
		goto IL_000f;
	}

IL_000f:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:104>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20538));
		Il2CppFullySharedGenericStruct* L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 106146
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Allocate_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_mCDBD1381CA662F016D4B6003D9BA89FE592EB6D8_gshared (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_count), (&___1_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20533));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20534));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20535));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:103>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20536));
		int64_t L_0 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_1 = ___1_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20537));
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_2;
		L_2 = Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3((MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)((uintptr_t)0), ((int64_t)0), L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20537));
		V_0 = L_2;
		goto IL_000f;
	}

IL_000f:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:104>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20538));
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 106147
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Free_TisIl2CppFullySharedGenericStruct_m6AA7597FA98F8020ABEFACEA0A1D00A384716627_gshared (Il2CppFullySharedGenericStruct* ___0_pointer, int64_t ___1_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool V_0 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_pointer), (&___1_count), (&___2_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20539));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20540));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20541));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:110>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20542));
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		V_0 = (bool)((((intptr_t)L_0) == ((intptr_t)((uintptr_t)0)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20543));
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000c;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:111>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20544));
		goto IL_0017;
	}

IL_000c:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:112>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20545));
		Il2CppFullySharedGenericStruct* L_2 = ___0_pointer;
		int64_t L_3 = ___1_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_4 = ___2_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20546));
		Il2CppFullySharedGenericStruct* L_5;
		L_5 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_2, L_3, ((int64_t)0), L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20546));
	}

IL_0017:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:113>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20547));
		return;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259* Array_Resize_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_m2DDF845DB5979955D328899EE0F362100AB78EA7_gshared (HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_mC5F44294D762B301009B393430DA9708D93DFBA1_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_m9B6FC2F3A48E1F92C8BA73C9A9801200E2124091(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251* Array_Resize_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mE778C4B3ECE88C4AE264C90DAA434AD967905C84_gshared (HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mEFDB11310E50096B062049FA90AC4E5950D68E88_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mBC2C631257DB33D5016220F5C7A5427FF2DACFF6(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4* Array_Resize_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_mAB4D8147B48337A05C319FEA2C8645B0DF7CC711_gshared (HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m3EB9C6E6DBEE5EBF53B76E36EC79986A0597AE52_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m0593078BB9DC842E2FE2C88E802B606CDC972402(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA* Array_Resize_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_m9051549FEC4CEBF8CE80DE8F2D26A95E80E9CE66_gshared (HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_mE0B20AEA610B5E2F0CC79058F8B1773FBD33256F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_m35FC0B97B1F13FB0FAA471381CCBB0CB3087BC97(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72_gshared (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* Array_Resize_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m56B4A5FA244655F35F0482ADF8BFAE16F683FAF1_gshared (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_mC94DEDD2611C7C84632B957D3FDB324F2C85EA7A(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2* Array_Resize_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_mDD4CF98E5E5E90B6E107726840D8A9BE281E4C07_gshared (UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_m25F773608FD4EA5E754AA43D5713B5168C86E212_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_mA92165B534B206808B571FE7817873636583F50A(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276_gshared (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* Array_Resize_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_mFF71C2DBFEFF6594159B5324E0EC19D878450E2E_gshared (UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m70E5F2C375F3B4039114929EBDF86DFCBF1EF99C(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E* Array_Resize_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m4C8664272ED00394CCBCA7A02C08A397452091DD_gshared (UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m88ED79EB396A32F9D6D47E040DD8509165D2061A_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m930BE4239F776EB5AE029CD112988F6AA9DB8F8B(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* Array_Resize_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_mCFE5759D51678924C8C9E90B0A2ABA0AEF5AB6F6_gshared (UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m756E0E44BD2515C8949896575600531B61F5B16B(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC* Array_Resize_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m6C351EB52C34B5CB7D9881124527BF376A4903A0_gshared (UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m42EC081A96F2D205655A9102710A6D4ADD494933_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m5565CF16739E9A5FFA05B4531E1F7DC4DE0ECA97(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378* Array_Resize_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_m47253003DD72BFD739EC472CD7D7675A19CBB733_gshared (UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_m9CFC6F1A283DF0509BEA73ABCC30711204347AEE_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_mEC999A534156D6D8DD89428B7B1F3F089410D7A4(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A_gshared (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0_gshared (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	uint8_t* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		uint8_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (uint8_t*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		uint8_t* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE_gshared (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		int32_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (int32_t*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		int32_t* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F_gshared (intptr_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	intptr_t* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		intptr_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (intptr_t*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		intptr_t* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t* Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81_gshared (uint64_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	uint64_t* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		uint64_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (uint64_t*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		uint64_t* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F_gshared (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726_gshared (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784_gshared (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4_gshared (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21_gshared (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Resize_TisIl2CppFullySharedGenericStruct_m07039200651D43DBB7FBC0CB244761DA34C164FD_gshared (Il2CppFullySharedGenericStruct* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	Il2CppFullySharedGenericStruct* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		Il2CppFullySharedGenericStruct* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (Il2CppFullySharedGenericStruct*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		Il2CppFullySharedGenericStruct* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 106145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3_gshared (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_oldPointer), (&___1_oldCount), (&___2_newCount), (&___3_allocator));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20525));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnity_Collections + 20526));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20527));
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:96>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20528));
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		int32_t L_4;
		L_4 = UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_inline(il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20529));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05(il2cpp_rgctx_method(method->rgctx_data, 2));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20530));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		void* L_6;
		L_6 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, ((int64_t)L_4), L_5, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20531));
		V_0 = (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)L_6;
		goto IL_0018;
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.unity.collections@aea9d3bd5e19/Unity.Collections/Memory.cs:97>
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnity_Collections + 20532));
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_7 = V_0;
		return L_7;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mED481D505BF43CBD96972069EDD4E3509BE84931_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(int32_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73409
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_gshared_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_source), (&___1_index));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2194));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2195));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2196));
		void* L_0 = ___0_source;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2197));
		int32_t L_1 = ___1_index;
		uint32_t L_2 = sizeof(int32_t);
		int32_t L_3 = (*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_1), ((int64_t)((int32_t)L_2))))))));
		return L_3;
	}
}
// Method Definition Index: 73405
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_gshared_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_ptr), (&___1_output));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2174));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2175));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2176));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2177));
		void* L_0 = ___0_ptr;
		int32_t* L_1 = ___1_output;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2178));
		UnsafeUtility_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D446ED46691A93FCA713FB662C464A32EC57539(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 1));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2178));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2179));
		return;
	}
}
// Method Definition Index: 11837
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* EqualityComparer_1_get_Default_m41DB4C0E0A508A8326E903331DC63D410B7AB9C4_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* V_0 = NULL;
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_0 = ((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mEBC7BD29A8FD796A4DAA1DF4428B95D1BA4FB377(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t209913D8BB9C5DF2E3F26BA94AD53F39604FBFB8* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 11837
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* EqualityComparer_1_get_Default_m7D273CC532DC2164C9C86D28C639FDEA38173C88_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* V_0 = NULL;
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_0 = ((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m22AF3135664449980749E1EC32EB92DB49219F9B(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tD96337BB993FF6246388ED223A24A3E752058F7B* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 11837
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* EqualityComparer_1_get_Default_m7F71AAC0046A3CB8C4CEB06A5A52A1269AF7023D_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* V_0 = NULL;
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_0 = ((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mD5EE323D1C48F0C09CBB944FA81707B8FEE2DB6D(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tE7F9CA4FFFE31F11BFD738023C1E489D3ECB371B* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 11837
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* EqualityComparer_1_get_Default_m80EE5C179E01BB38904781592AC72F8137541D7E_gshared_inline (const RuntimeMethod* method) 
{
	EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* V_0 = NULL;
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_0 = ((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m5F906E9B13BCCCDF51EF0852BD9E5E0065D185F8(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		V_0 = L_2;
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 2)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t8B3F40C676CD330DB13D396DB81564A00E2B7C70* L_4 = V_0;
		return L_4;
	}
}
// Method Definition Index: 73256
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool NativeArray_1_get_IsCreated_m478F812F31DEC928EC9D697C47C7E188CCA0010F_gshared_inline (NativeArray_1_t0BB246A2F65C2C705F83BEBE1B62D9543C330B70* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_t6E2931CC2E1AA6B9F666FF4270BD177E2114779B_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 1237));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 1238));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 1239));
		void* L_0 = __this->___m_Buffer;
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)((uintptr_t)0)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259_mC5F44294D762B301009B393430DA9708D93DFBA1_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(HashMapHelper_1_t9CB6B25EDA71DB75518C8E491E2F6935C93F7259);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251_mEFDB11310E50096B062049FA90AC4E5950D68E88_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(HashMapHelper_1_tA9B75C8F9CC29B07AE1E9886F8F7819DAF6FE251);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4_m3EB9C6E6DBEE5EBF53B76E36EC79986A0597AE52_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(HashMapHelper_1_t02163850B336A3F6BBE330638EECFA3CBFCB8CC4);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA_mE0B20AEA610B5E2F0CC79058F8B1773FBD33256F_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(HashMapHelper_1_tE8E7D655F29F468DA51567821366BF4DAE24D8CA);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m8058188B2884F5674C5A4C9C7AFC0A59000CC56F_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisHashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F_m3446503708EF53FF3664993B371F061F2C98A44F_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(HashMapHelper_1_tA254628934FEBA6864D3561F28C85E02EA1CD06F);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2_m25F773608FD4EA5E754AA43D5713B5168C86E212_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_tBCB0E76D5EC755D50DC298D12667FF32835184D2);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m9DD3BAE2675B37478EA2C9AA9DAFD2C6C1F5BF4E_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD_m201D21D3AC9187C9EFEF16F0B593FAC6BE19EE72_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0F79CBE5DEA60DE3AE33082C3F7F324FE9066ECD);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E_m88ED79EB396A32F9D6D47E040DD8509165D2061A_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_t8131D7A089A7E34FF4B5572E5F0D6C419ADD433E);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515_m067749C993CAF4A3AA0673C46673216D995516DE_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_t927BA8F9B687AB3656D5A6FFCD1AEE5BE72A5515);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC_m42EC081A96F2D205655A9102710A6D4ADD494933_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_t369255B1A1AFDBCC4B50BCC7BDB9CD1F2681A3CC);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378_m9CFC6F1A283DF0509BEA73ABCC30711204347AEE_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueue_1_t36E4B63727861C2FA069DAD6116E331F81312378);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m9108AF5F196154FF71AD62376A7411B92391F000_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m97C7D5E5DE74DC60A0ECAA914830BEDF2C46ACAA_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(uint8_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisIntPtr_t_mB2B3CFF1CB804C99734D4E2F5D8A8C9DB0D209A8_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(intptr_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m6C198B51ACD7B8EC62D5E0E75433C12BE9D65A58_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(uint64_t);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mCCA7CED28D808054F7C94E1BF58205316AEE194F_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mB6FE4CAF35894EF5E357881DA5A0EAE9EDAD3754_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mEBEAA7CA1C71A37FA5CBCF89A0C9B78ABAD5C8C7_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m25193E03B20C96400F243B7A682AF5BB8F030297_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m79CAC169FC4593612624CB619E7D6F6FD7447517_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67);
		return (int32_t)L_0;
	}
}
// Method Definition Index: 73414
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m4A0947EA519A2614EC19544513888A4DC5F42919_gshared_inline (const RuntimeMethod* method) 
{
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, method, NULL, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2214));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2215));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 2216));
		uint32_t L_0 = sizeof(MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84);
		return (int32_t)L_0;
	}
}
