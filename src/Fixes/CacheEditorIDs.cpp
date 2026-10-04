#include "Fixes/CacheEditorIDs.h"

//Cache skipped formEditorIDs
namespace Fixes::CacheEditorIDs
{
	void Install()
	{
		HookEditorID<RE::BGSFormFolderKeywordList>(1);
		HookEditorID<RE::BGSTransform>(1);
		HookEditorID<RE::BGSTextureSet>(0);
		HookEditorID<RE::BGSDamageType>(2);
		HookEditorID<RE::TESClass>(5);
		HookEditorID<RE::TESFaction>(3);
		HookEditorID<RE::BGSAffinityEvent>(1);

		// empty
		//HookEditorID<RE::TESEyes>(0);

		HookEditorID<RE::TESSound>(3);
		HookEditorID<RE::BGSSoundEcho>(1);
		HookEditorID<RE::BGSAcousticSpace>(1);
		HookEditorID<RE::BGSAudioOcclusionPrimitive>(1);
		HookEditorID<RE::EffectSetting>(3);
		HookEditorID<RE::BGSProjectedDecal>(0);
		HookEditorID<RE::EnchantmentItem>(2);
		HookEditorID<RE::SpellItem>(8);
		HookEditorID<RE::TESObjectACTI>(10);

		// nothing uses it?
		// HookEditorID<RE::BGSTalkingActivator>(9);

		HookEditorID<RE::BGSCurveForm>(0);
		HookEditorID<RE::BGSCurve3DForm>(0);
		HookEditorID<RE::TESObjectBOOK>(3);
		HookEditorID<RE::TESObjectCONT>(5);

		// loading skipped
		// HookEditorID<RE::TESObjectDOOR>(4);

		HookEditorID<RE::TESObjectLIGH>(9);
		HookEditorID<RE::TESObjectMISC>(4);
		HookEditorID<RE::TESObjectSTAT>(0);
		HookEditorID<RE::BGSStaticCollection>(0);
		HookEditorID<RE::BGSPackIn>(3);
		HookEditorID<RE::BGSMovableStatic>(6);
		HookEditorID<RE::TESGrass>(2);
		HookEditorID<RE::TESFlora>(4);
		HookEditorID<RE::TESFurniture>(4);
		HookEditorID<RE::TESAmmo>(3);
		HookEditorID<RE::TESNPC>(15);
		HookEditorID<RE::TESLevCharacter>(3);
		HookEditorID<RE::BGSLevPackIn>(2);
		HookEditorID<RE::TESKey>(12);
		HookEditorID<RE::AlchemyItem>(8);
		HookEditorID<RE::BGSIdleMarker>(3);
		HookEditorID<RE::BGSBiomeMarkerObject>(3);
		HookEditorID<RE::BGSProjectile>(0);
		HookEditorID<RE::BGSHazard>(0);
		HookEditorID<RE::BGSBendableSpline>(0);
		HookEditorID<RE::BGSTerminal>(6);
		HookEditorID<RE::TESLevItem>(4);
		HookEditorID<RE::BGSLevGenericBaseForm>(3);
		HookEditorID<RE::TESWeather>(1);
		HookEditorID<RE::BGSWeatherSettingsForm>(1);
		HookEditorID<RE::TESClimate>(0);
		HookEditorID<RE::BGSShaderParticleGeometryData>(0);
		HookEditorID<RE::TESRegion>(1);
		HookEditorID<RE::TESTopicInfo>(0);
		HookEditorID<RE::TESPackage>(1);
		HookEditorID<RE::TESCombatStyle>(1);
		HookEditorID<RE::TESLoadScreen>(1);
		HookEditorID<RE::TESWaterForm>(0);
		HookEditorID<RE::TESEffectShader>(0);
		HookEditorID<RE::BGSExplosion>(2);
		HookEditorID<RE::BGSDebris>(2);
		HookEditorID<RE::TESImageSpace>(0);
		HookEditorID<RE::BGSListForm>(1);
		HookEditorID<RE::BGSPerk>(3);
		HookEditorID<RE::BGSBodyPartData>(0);

		// loading skipped
		// HookEditorID<RE::BGSAddonNode>(2);

		// hangs credit menu
		// HookEditorID<RE::BGSCameraShot>(1);
		// HookEditorID<RE::BGSCameraPath>(0);

		HookEditorID<RE::BGSMaterialType>(0);
		HookEditorID<RE::BGSImpactData>(0);
		HookEditorID<RE::BGSImpactDataSet>(0);
		HookEditorID<RE::BGSMessage>(0);
		HookEditorID<RE::BGSLightingTemplate>(0);

		// loading skipped ?
		//HookEditorID<RE::BGSFootstep>(1);

		HookEditorID<RE::BGSFootstepSet>(1);

		// didn't RE
		// HookEditorID<RE::BGSStoryManagerBranchNode>(1);
		// HookEditorID<RE::BGSStoryManagerQuestNode>(0);
		// HookEditorID<RE::BGSDialogueBranch>(1);
		// HookEditorID<RE::BGSMusicTrackFormWrapper>(0);

		HookEditorID<RE::BGSOutfit>(1);
		HookEditorID<RE::BGSArtObject>(2);
		HookEditorID<RE::BGSMovementType>(1);
		HookEditorID<RE::BGSCollisionLayer>(1);
		HookEditorID<RE::BGSColorForm>(1);
		HookEditorID<RE::BGSReverbParameters>(0);
		HookEditorID<RE::BGSAimModel>(0);
		HookEditorID<RE::BGSAimAssistModel>(0);
		HookEditorID<RE::BGSMeleeAimAssistModel>(0);
		HookEditorID<RE::BGSConstructibleObject>(6);
		HookEditorID<RE::BGSMod::Attachment::Mod>(4);
		HookEditorID<RE::BGSAimDownSightModel>(0);
		HookEditorID<RE::BGSInstanceNamingRules>(1);
		HookEditorID<RE::BGSSoundKeywordMapping>(1);
		HookEditorID<RE::BGSSoundTagSet>(0);
		HookEditorID<RE::BGSLensFlare>(0);
		HookEditorID<RE::BGSSnapTemplateNode>(0);
		HookEditorID<RE::BGSSnapTemplate>(1);
		HookEditorID<RE::BGSGroundCover>(1);
		HookEditorID<RE::BGSTraversal>(0);
		HookEditorID<RE::BGSResourceGenerationData>(0);
		HookEditorID<RE::BGSObjectSwap>(1);
		HookEditorID<RE::BGSAtmosphere>(1);

		// loading skipped
		// HookEditorID<RE::BGSLevSpaceCell>(0);

		HookEditorID<RE::BGSSpeechChallengeObject>(0);

		// loading skipped
		// HookEditorID<RE::BGSAimAssistPoseData>(1);

		HookEditorID<RE::BGSVolumetricLighting>(0);
		HookEditorID<RE::BGSSurface::Block>(1);
		HookEditorID<RE::BGSSurface::Pattern>(1);
		HookEditorID<RE::BGSSurface::Tree>(1);

		// didn't RE
		// HookEditorID<RE::BGSPlanetContentManagerTree>(0);

		// loading skipped
		// HookEditorID<RE::BGSBoneModifier>(0);

		HookEditorID<RE::BGSSnapBehavior>(1);
		HookEditorID<RE::BGSPlanet::PlanetData>(1);
		HookEditorID<RE::BGSConditionForm>(1);

		// didn't RE
		// HookEditorID<RE::BGSPlanetContentManagerBranchNode>(1);
		// HookEditorID<RE::BGSPlanetContentManagerContentNode>(1);

		HookEditorID<RE::BSGalaxy::BGSStar>(1);
		HookEditorID<RE::BGSResearchProjectForm>(2);
		HookEditorID<RE::BGSAimOpticalSightModel>(0);
		HookEditorID<RE::BGSAmbienceSet>(1);
		HookEditorID<RE::BGSWeaponBarrelModel>(1);
		HookEditorID<RE::BGSSurface::PatternStyle>(0);
		HookEditorID<RE::BGSLayeredMaterialSwap>(2);
		HookEditorID<RE::BGSForceData>(0);
		HookEditorID<RE::BGSTerminalMenu>(0);
		HookEditorID<RE::BGSEffectSequenceForm>(1);
		HookEditorID<RE::BGSSecondaryDamageList>(1);
		HookEditorID<RE::BGSMaterialPathForm>(0);
		HookEditorID<RE::BGSCloudForm>(1);
		HookEditorID<RE::BGSFogVolumeForm>(0);
		HookEditorID<RE::BGSWwiseKeywordMapping>(1);

		// loading skipped
		// HookEditorID<RE::BGSLegendaryItem>(1);

		HookEditorID<RE::BGSParticleSystemDefineCollection>(1);
		HookEditorID<RE::BSGalaxy::BGSSunPresetForm>(1);
		HookEditorID<RE::BGSPhotoModeFeature>(2);
		HookEditorID<RE::BGSTimeOfDayData>(1);

		// loading skipped
		// HookEditorID<RE::TESDataHandlerPersistentCreatedUtil::BGSPersistentIDsForm>(1);

		HookEditorID<RE::BGSChallengeForm>(1);

		REX::INFO("\tInstalled editorID cache"sv);
	}
}
