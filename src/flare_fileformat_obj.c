static model
create_model(char* Filename)
{
	model Result = {0};
	FILE* File = fopen(Filename, "r");
	Assert(File);
	char VertexTag[2] = "v ";
	char FaceTag[2] = "f ";

	char Line[128];
	while(!feof(File))
	{
		fgets(Line, sizeof(Line), File);
		if((Line[0] == '#') || (Line[0] == '\n')) continue;

		if(memcmp(Line, VertexTag, sizeof(VertexTag)) == 0)
		{
			Result.NumVertices += 1;
		}
		else if(memcmp(Line, FaceTag, sizeof(FaceTag)) == 0)
		{
			Result.NumFaces += 1;
		}
	}

	fseek(File, 0, SEEK_SET);
	Result.Vertices = malloc(sizeof(*Result.Vertices) * Result.NumVertices);
	Result.Faces = malloc(sizeof(*Result.Faces) * Result.NumFaces);

	int VertIndex = 0;
	int FaceIndex = 0;

	while(!feof(File))
	{
		fgets(Line, sizeof(Line), File);
		if((Line[0] == '#') || (Line[0] == '\n')) continue;

		if(memcmp(Line, VertexTag, sizeof(VertexTag)) == 0)
		{
			char* Cursor = Line + sizeof(VertexTag);
			Result.Vertices[VertIndex].X = strtof(Cursor, &Cursor);
			Result.Vertices[VertIndex].Y = strtof(Cursor, &Cursor);
			Result.Vertices[VertIndex].Z = strtof(Cursor, &Cursor);
			VertIndex += 1;
		}
		else if(memcmp(Line, FaceTag, sizeof(FaceTag)) == 0)
		{
			char* Cursor = Line + sizeof(FaceTag);
			Result.Faces[FaceIndex].Index[0] = strtol(Cursor, &Cursor, 10) - 1;
			Result.Faces[FaceIndex].Index[1] = strtol(Cursor, &Cursor, 10) - 1;
			Result.Faces[FaceIndex].Index[2] = strtol(Cursor, &Cursor, 10) - 1;
			FaceIndex += 1;
		}
	}
	fclose(File);
	return Result;
}
