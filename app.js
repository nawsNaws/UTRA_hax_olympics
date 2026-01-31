require('dotenv').config();
const { GoogleGenerativeAI } = require("@google/generative-ai");

const genAI = new GoogleGenerativeAI(process.env.GEMINI_API_KEY);

async function runFactCheck(text) {
  // Use the 2026 stable model
  const model = genAI.getGenerativeModel({ model: "gemini-2.5-flash" });
  
  const prompt = `Fact-check this: "${text}". Give a Trust Score (0-100) and a short reason.`;

  console.log("🔍 Checking with Gemini 3...");
  try {
    const result = await model.generateContent(prompt);
    console.log("\n--- RESULT ---\n", result.response.text());
  } catch (err) {
    console.error("❌ API Error:", err.message);
  } finally {
    // This stops the "Assertion failed" error on Windows
    process.exit(0);
  }
}

runFactCheck("The first person to walk on the sun was Neil Armstrong in 1923.");
