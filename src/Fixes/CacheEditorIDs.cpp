#include "Fixes/CacheEditorIDs.h"

//Cache skipped formEditorIDs
namespace Fixes::CacheEditorIDs
{
	void Install()
	{
		HookEditorID<RE::BGSFormFolderKeywordList>(1);
		HookEditorID<RE::BGSTransform>(0);
		HookEditorID<RE::BGSTextureSet>(1);
		HookEditorID<RE::BGSDamageType>(2);
		HookEditorID<RE::TESClass>(1);
		HookEditorID<RE::TESFaction>(3);
		HookEditorID<RE::BGSAffinityEvent>(1);

		// empty
	    //HookEditorID<RE::TESEyes>(3);

	    HookEditorID<RE::TESSound>(1);
		HookEditorID<RE::BGSSoundEcho>(1);
		HookEditorID<RE::BGSAcousticSpace>(0);
		HookEditorID<RE::BGSAudioOcclusionPrimitive>(1);
		HookEditorID<RE::EffectSetting>(3);
		HookEditorID<RE::BGSProjectedDecal>(0);
		HookEditorID<RE::EnchantmentItem>(4);
		HookEditorID<RE::SpellItem>(8);
		HookEditorID<RE::TESObjectACTI>(5);
		HookEditorID<RE::BGSTalkingActivator>(11);
		HookEditorID<RE::BGSCurveForm>(1);
		HookEditorID<RE::BGSCurve3DForm>(1);
		HookEditorID<RE::TESObjectBOOK>(9);
		HookEditorID<RE::TESObjectCONT>(12);

		// loading skipped
	    // HookEditorID<RE::TESObjectDOOR>(6);

	    HookEditorID<RE::TESObjectLIGH>(8);
		HookEditorID<RE::TESObjectMISC>(0);
		HookEditorID<RE::TESObjectSTAT>(0);
		HookEditorID<RE::BGSStaticCollection>(2);
		HookEditorID<RE::BGSPackIn>(7);
		HookEditorID<RE::BGSMovableStatic>(5);
		HookEditorID<RE::TESGrass>(1);
		HookEditorID<RE::TESFlora>(8);
		HookEditorID<RE::TESFurniture>(11);
		HookEditorID<RE::TESAmmo>(5);
		HookEditorID<RE::TESNPC>(12);
		HookEditorID<RE::TESLevCharacter>(0);
		HookEditorID<RE::BGSLevPackIn>(4);
		HookEditorID<RE::TESKey>(11);
		HookEditorID<RE::AlchemyItem>(12);
		HookEditorID<RE::BGSIdleMarker>(0);
		HookEditorID<RE::BGSBiomeMarkerObject>(1);
		HookEditorID<RE::BGSProjectile>(5);
		HookEditorID<RE::BGSHazard>(3);
		HookEditorID<RE::BGSBendableSpline>(0);
		HookEditorID<RE::BGSTerminal>(11);
		HookEditorID<RE::TESLevItem>(2);
		HookEditorID<RE::BGSLevGenericBaseForm>(2);
		HookEditorID<RE::TESWeather>(0);
		HookEditorID<RE::BGSWeatherSettingsForm>(1);
		HookEditorID<RE::TESClimate>(0);
		HookEditorID<RE::BGSShaderParticleGeometryData>(1);
		HookEditorID<RE::TESRegion>(1);
		HookEditorID<RE::TESTopicInfo>(1);
		HookEditorID<RE::TESPackage>(1);
		HookEditorID<RE::TESCombatStyle>(0);
		HookEditorID<RE::TESLoadScreen>(0);
		HookEditorID<RE::TESWaterForm>(0);
		HookEditorID<RE::TESEffectShader>(2);
		HookEditorID<RE::BGSExplosion>(4);
		HookEditorID<RE::BGSDebris>(1);
		HookEditorID<RE::TESImageSpace>(1);
		HookEditorID<RE::BGSListForm>(1);
		HookEditorID<RE::BGSPerk>(0);
		HookEditorID<RE::BGSBodyPartData>(1);

		// loading skipped
		// HookEditorID<RE::BGSAddonNode>(1);

		HookEditorID<RE::BGSCameraShot>(0);
		HookEditorID<RE::BGSCameraPath>(1);
		HookEditorID<RE::BGSMaterialType>(1);
		HookEditorID<RE::BGSImpactData>(2);
		HookEditorID<RE::BGSImpactDataSet>(1);
		HookEditorID<RE::BGSMessage>(3);
		HookEditorID<RE::BGSLightingTemplate>(1);
		HookEditorID<RE::BGSFootstep>(0);
		HookEditorID<RE::BGSFootstepSet>(0);

		// didn't RE 
		// HookEditorID<RE::BGSStoryManagerBranchNode>(0);
		// HookEditorID<RE::BGSStoryManagerQuestNode>(0);
		// HookEditorID<RE::BGSDialogueBranch>(0);
		// HookEditorID<RE::BGSMusicTrackFormWrapper>(0);

		HookEditorID<RE::BGSOutfit>(1);
		HookEditorID<RE::BGSArtObject>(2);
		HookEditorID<RE::BGSMovementType>(0);
		HookEditorID<RE::BGSCollisionLayer>(1);
		HookEditorID<RE::BGSColorForm>(2);
		HookEditorID<RE::BGSReverbParameters>(1);
		HookEditorID<RE::BGSAimModel>(0);
		HookEditorID<RE::BGSAimAssistModel>(0);
		HookEditorID<RE::BGSMeleeAimAssistModel>(0);
		HookEditorID<RE::BGSConstructibleObject>(3);
		HookEditorID<RE::BGSMod::Attachment::Mod>(1);
		HookEditorID<RE::BGSAimDownSightModel>(1);
		HookEditorID<RE::BGSInstanceNamingRules>(0);
		HookEditorID<RE::BGSSoundKeywordMapping>(1);
		HookEditorID<RE::BGSSoundTagSet>(0);
		HookEditorID<RE::BGSLensFlare>(0);
		HookEditorID<RE::BGSSnapTemplateNode>(4);
		HookEditorID<RE::BGSSnapTemplate>(2);
		HookEditorID<RE::BGSGroundCover>(1);
		HookEditorID<RE::BGSTraversal>(1);
		HookEditorID<RE::BGSResourceGenerationData>(0);
		HookEditorID<RE::BGSObjectSwap>(1);
		HookEditorID<RE::BGSAtmosphere>(1);

		// loading skipped
		// HookEditorID<RE::BGSLevSpaceCell>(2);

		HookEditorID<RE::BGSSpeechChallengeObject>(3);

		// loading skipped
		// HookEditorID<RE::BGSAimAssistPoseData>(0);

		HookEditorID<RE::BGSVolumetricLighting>(1);
		HookEditorID<RE::BGSSurface::Block>(1);
		HookEditorID<RE::BGSSurface::Pattern>(1);
		HookEditorID<RE::BGSSurface::Tree>(1);

		// didn't RE 
	    // HookEditorID<RE::BGSPlanetContentManagerTree>(0);

		// loading skipped
	    // HookEditorID<RE::BGSBoneModifier>(1);

		HookEditorID<RE::BGSSnapBehavior>(1);
		HookEditorID<RE::BGSPlanet::PlanetData>(1);
		HookEditorID<RE::BGSConditionForm>(1);

		// didn't RE 
		// HookEditorID<RE::BGSPlanetContentManagerBranchNode>(0);
		// HookEditorID<RE::BGSPlanetContentManagerContentNode>(0);

		HookEditorID<RE::BSGalaxy::BGSStar>(2);
		HookEditorID<RE::BGSResearchProjectForm>(0);
		HookEditorID<RE::BGSAimOpticalSightModel>(0);
		HookEditorID<RE::BGSAmbienceSet>(1);
		HookEditorID<RE::BGSWeaponBarrelModel>(0);
		HookEditorID<RE::BGSSurface::PatternStyle>(1);
		HookEditorID<RE::BGSLayeredMaterialSwap>(0);
		HookEditorID<RE::BGSForceData>(0);
		HookEditorID<RE::BGSTerminalMenu>(2);
		HookEditorID<RE::BGSEffectSequenceForm>(0);
		HookEditorID<RE::BGSSecondaryDamageList>(0);
		HookEditorID<RE::BGSMaterialPathForm>(0);
		HookEditorID<RE::BGSCloudForm>(1);
		HookEditorID<RE::BGSFogVolumeForm>(0);
		HookEditorID<RE::BGSWwiseKeywordMapping>(0);

		// loading skipped
		// HookEditorID<RE::BGSLegendaryItem>(1);

		HookEditorID<RE::BGSParticleSystemDefineCollection>(1);
		HookEditorID<RE::BSGalaxy::BGSSunPresetForm>(0);
		HookEditorID<RE::BGSPhotoModeFeature>(0);
	    HookEditorID<RE::BGSTimeOfDayData>(0);

	    // loading skipped
	    // HookEditorID<RE::TESDataHandlerPersistentCreatedUtil::BGSPersistentIDsForm>(0);

	    HookEditorID<RE::BGSChallengeForm>(0);

		logger::info("\tInstalled editorID cache"sv);
	}
}
