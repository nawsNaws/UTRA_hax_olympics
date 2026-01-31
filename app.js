// ... (previous setup code)

app.post('/audit', upload.single('productImage'), async (req, res) => {
  try {
    const filePath = req.file.path;
    // Using Gemini 3 Flash for the fastest multimodal processing
    const model = genAI.getGenerativeModel({ 
        model: "gemini-3-flash",
        generationConfig: { responseMimeType: "application/json" } 
    });

    const imageData = {
      inlineData: {
        data: Buffer.from(fs.readFileSync(filePath)).toString("base64"),
        mimeType: req.file.mimetype
      }
    };

    const prompt = `
      Analyze this food label. Return a JSON object with this exact structure:
      {
        "health_grade": "A-F",
        "summary": "one sentence summary",
        "analysis": [
          {"ingredient": "name", "type": "Benefit/Risk", "reason": "why"}
        ]
      }
    `;

    const result = await model.generateContent([prompt, imageData]);
    res.json(JSON.parse(result.response.text())); // Send the raw JSON to the frontend
    fs.unlinkSync(filePath);
  } catch (error) {
    res.status(500).json({ error: error.message });
  }
});
