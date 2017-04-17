void Import_GDML_Export_ROOT(TString filename)
{
	// Check that the input file is the GDML file
	if (!filename.EndsWith(".gdml")) {
		cerr << "Please specify a GDML file as input!" << endl;
		return;
	}

	// Create geometry manager
	TGeoManager* geom = new TGeoManager("geom", "geom");

	// Create GDML parser
	TGDMLParse parser;
	TGeoVolume* gdmlTop = parser.GDMLReadFile(filename);
/*
	// Create one more volume to contain everything imported from the GDML file
	TGeoVolume* rootTop = new TGeoVolumeAssembly("TOP");
  
	// Define your position HERE
	TGeoRotation* rot = new TGeoRotation ("rot", 0., 0., 0.);
	TGeoCombiTrans* posrot = new TGeoCombiTrans (0., 0., 0., rot);

	// Put the geometry from the GDML file into the new top volume
	rootTop->AddNode(gdmlTop, 1, posrot);
*/
	// Set the top volume
	gGeoManager->SetTopVolume(gdmlTop); // rootTop or gdmlTop

	// Close the geometry manager
	gGeoManager->CloseGeometry();

	// Define you output ROOT file name HERE
	TString outFilename;
	outFilename.Form("%s.root", filename.Data());

	// Export geometry manager into the output ROOT file
	TFile* outfile = new TFile(outFilename, "RECREATE");
	geom->Write();
	outfile->Close();  
}
